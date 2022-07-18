#include "calcdelay_socket_udp.hpp"

namespace calcdelay
{
CalcDelaySockUdp::CalcDelaySockUdp(globalconfig  &gcfg) : CalcDelaySock(gcfg)
{

}

CalcDelaySockUdp::~CalcDelaySockUdp()
{
    Close();
}

int CalcDelaySockUdp::SetSock()
{
    struct ifreq hwtstamp;
    struct hwtstamp_config hwconfig;
    memset(&hwtstamp, 0, sizeof(hwtstamp)); 
    memset(&hwconfig, 0, sizeof(hwconfig)); 
    strncpy(hwtstamp.ifr_name, gcfg.ccfg.nicdevice.c_str(),sizeof(hwtstamp.ifr_name) - 1);
    hwtstamp.ifr_data = (__caddr_t )&hwconfig;

    // 设置网卡捕获所有发送报文的硬件时间戳。
    hwconfig.tx_type = HWTSTAMP_TX_ON;

    // 设置网卡捕获所有接收到的报文的时间戳。 
    hwconfig.rx_filter = HWTSTAMP_FILTER_ALL;
    ioctl(gcfg.scfg.sockfd, SIOCSHWTSTAMP, &hwtstamp);


    int tsflags;
    if(gcfg.ccfg.timestamping == HARDWARESTR)
    {
        tsflags =   SOF_TIMESTAMPING_TX_HARDWARE |
                    SOF_TIMESTAMPING_RX_HARDWARE |
                    SOF_TIMESTAMPING_RAW_HARDWARE;
    }
    else if(gcfg.ccfg.timestamping == SOFTWARESTR)
    {
        tsflags =   SOF_TIMESTAMPING_TX_SOFTWARE |
                    SOF_TIMESTAMPING_RX_SOFTWARE |
                    SOF_TIMESTAMPING_SOFTWARE;
    }

    if(setsockopt(gcfg.scfg.sockfd, SOL_SOCKET, SO_TIMESTAMPING, &tsflags, sizeof(tsflags)) < 0)
    {
        perror("Setsock SO_TIMESTAMPING Failed!");
        return -1;
    }

    if(setsockopt(gcfg.scfg.sockfd, SOL_IP, IP_TOS, &gcfg.ccfg.tos, sizeof(gcfg.ccfg.tos)) < 0)
    {
        perror("Setsock IP_TOS failed!");
        return -1;
    }

    int reuseflag = 1; 
    if(setsockopt(gcfg.scfg.sockfd, SOL_SOCKET, SO_REUSEADDR, &reuseflag, sizeof(reuseflag)) < 0)
    {
        perror("Setsock SO_REUSEADDR failed!");
        return -1;
    }

    int errflag = 1;
    if(setsockopt(gcfg.scfg.sockfd, SOL_SOCKET, SO_SELECT_ERR_QUEUE, &errflag, sizeof(errflag)) < 0)
    {
        perror("SO_SELECT_ERR_QUEUE Failed");
    }

    return 0;
}

int CalcDelaySockUdp::Bind() 
{
    if(gcfg.ccfg.runningmode == "server")
    {
        if(bind(gcfg.scfg.sockfd, (sockaddr*)&gcfg.scfg.localaddr, sizeof(gcfg.scfg.localaddr)) < 0)
        {
            perror("TCP sock bind error");
            return -1;
        }
        std::cout << "UDP Sock Bind Success!" << std::endl;
    }
    return 0;
}

int CalcDelaySockUdp::Listen()
{
    return 0;
}

int CalcDelaySockUdp::Connect()
{
    return 0;
}

int CalcDelaySockUdp::Accept()
{
    return 0;
}

int CalcDelaySockUdp::Send()
{
    int ret = 0;
    char tmpbuf[512];
    memset(sendbuf,1,MESSAGESIZE);
    clock_gettime(CLOCK_REALTIME, &systemts);
    if((ret = sendto(gcfg.scfg.sockfd, sendbuf, sizeof(sendbuf), 0, (sockaddr *)&gcfg.scfg.remoteaddr, sizeof(gcfg.scfg.remoteaddr))) < 0)
    {
        perror("UDP Send Failed!");
        return ret;
    }

    return SkRecv(gcfg.scfg.sockfd, tmpbuf, sizeof(tmpbuf), gcfg.scfg.remoteaddr, MSG_ERRQUEUE);
}

int CalcDelaySockUdp::Recv(int flag)
{
    int ret = SkRecv(gcfg.scfg.sockfd, recvbuf, sizeof(recvbuf), gcfg.scfg.remoteaddr, flag);
    
    int64_t b   = TimeSpec2Ns(systemts);
    int64_t a   = TimeSpec2Ns(hardwarets);
    int64_t delay = (int64_t)abs(a - b);
    
    std::cout << "rx system timesstamp:" << b << std::endl;
    std::cout << "rx hardware timesstamp:" <<a << std::endl;
    std::cout << "rxdelay:" << delay << std::endl;
    std::cout << "recv msg:" << recvbuf << std::endl;

    return ret;
}

char* CalcDelaySockUdp::GetSendBuf()
{
    return sendbuf;
}

char* CalcDelaySockUdp::GetRecvBuf()
{
    return recvbuf;
}

int CalcDelaySockUdp::Close()
{
    if(close(gcfg.scfg.sockfd))
    {
        perror("UDP sockfd Close Failed!");
        return -1;
    }

    return 0;
}

}   //  namespace calcdelay