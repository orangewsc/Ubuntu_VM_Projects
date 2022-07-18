#include "calcdelay_socket.hpp"

namespace calcdelay
{

CalcDelaySock::CalcDelaySock(globalconfig &gcfg)
{
    this->gcfg  = gcfg;
}

int64_t CalcDelaySock::TimeSpec2Ns(struct timespec& ts)
{
    return (int64_t)ts.tv_sec * kNsInSec + (int64_t)ts.tv_nsec;
}

int64_t CalcDelaySock::GetDelay()
{
    int64_t b   = TimeSpec2Ns(systemts);
    int64_t a   = TimeSpec2Ns(hardwarets);
    delay       = (int64_t)abs(a - b);
    std::cout << "tx system timesstamp:" << b << std::endl;

    
    std::cout << "tx hardware timesstamp:" <<a << std::endl;

    
    std::cout << "delay:" << delay << std::endl;

    return  delay;
}

int CalcDelaySock::SkRecv(int sockfd, void* buf, int buflen, 
                            struct sockaddr_in addr, int flags)
{
    struct  timespec *ts;    
    struct  msghdr  msg;
    struct  cmsghdr *cm;
    struct  iovec   iov = {buf, buflen};
    char    control[512];
    int     ret = 0, cnt = 0, level = 0, type = 0, timeout = 100;

    memset(control, 0, sizeof(control));
    memset(&msg, 0, sizeof(msg));
    msg.msg_name        = (struct sockaddr *)&addr;
    msg.msg_namelen     = sizeof(sockaddr_in);
    msg.msg_iov         = &iov;
    msg.msg_iovlen      = 1;
    msg.msg_control     = control;
    msg.msg_controllen  = sizeof(control);

    if(flags == MSG_ERRQUEUE)
    {
        struct pollfd   pfd = {sockfd, sk_events, 0};
        ret = poll(&pfd, 1, timeout);
        if(ret < 1)
        {
            perror("poll for timestamp failed");
            return -1;
        }
        else if(!(pfd.revents & sk_revents))
        {
            perror("poll for tx timestamp woke up on non ERR event");
            return -1;
        }

    }

    cnt = recvmsg(sockfd, &msg, flags);

    if(cnt < 0)
    {
        std::cout << "recv msg failed" << (flags == MSG_ERRQUEUE ? "tx timestamp" : " ") << std::endl;
    }
    
    for(cm = CMSG_FIRSTHDR(&msg); cm!=NULL; cm = CMSG_NXTHDR(&msg, cm))
    {
        level = cm->cmsg_level;
        type  = cm->cmsg_type;
        if(level == SOL_SOCKET && type == SO_TIMESTAMPING)
        {
            if(cm->cmsg_len < sizeof(*ts)*3)
            {
                perror("short SO_TIMESTAMPING message");
                return -1;
            }
            ts = (struct timespec *) CMSG_DATA(cm);
        }
    }

    if(!ts)
    {
        perror("CMSG_DATA get ts error");
        return -1;
    }

    bool tmp = (gcfg.ccfg.timestamping == HARDWARESTR) ? 0 : 1;
    switch (tmp)
    {
    case HARDWARE:
        hardwarets = ts[2];
        break;
    case SOFTWARE:
        hardwarets = ts[0];
        break;
    default:
        break;
    }

    return cnt < 0 ? -errno : cnt;

}
}