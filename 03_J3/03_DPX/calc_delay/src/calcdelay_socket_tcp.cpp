#include "calcdelay_socket_tcp.hpp"


namespace calcdelay
{
CalcDelaySockTcp::CalcDelaySockTcp(globalconfig  &gcfg) : CalcDelaySock(gcfg)
{
    
}

CalcDelaySockTcp::~CalcDelaySockTcp()
{
    Close();
}

int CalcDelaySockTcp::SetSock()
{

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


    return 0;
}

int CalcDelaySockTcp::Bind() 
{
    if(gcfg.ccfg.runningmode == "server")
    {
        if(bind(gcfg.scfg.sockfd, (sockaddr*)&gcfg.scfg.localaddr, sizeof(gcfg.scfg.localaddr)) < 0)
        {
            perror("TCP Sock Bind Error");
            return -1;
        }
    }
    std::cout << "TCP Sock Bind Success!" << std::endl;
    return 0;
}

int CalcDelaySockTcp::Listen()
{
    if(gcfg.ccfg.runningmode == "server" && gcfg.ccfg.protocol == TCP)
    {
        if(listen(gcfg.scfg.sockfd,10) < 0)
        {
            perror("TCP Sock Listen Error");
            return -1;
        }
    }
    std::cout << "TCP Sock Listen Success!" << std::endl;
    return 0;
}

int CalcDelaySockTcp::Connect()
{
    if(gcfg.ccfg.runningmode == "client" && gcfg.ccfg.protocol == TCP)
    {
        while(connect(gcfg.scfg.sockfd, (sockaddr *)&gcfg.scfg.remoteaddr, (socklen_t )sizeof(gcfg.scfg.remoteaddr)) < 0)
        {
            perror("TCP Sock Connect Failed!");
        }
        clientfd = gcfg.scfg.sockfd;
        std::cout << "TCP Sock Connect Success!" << std::endl;
    }
    return 0;
}

int CalcDelaySockTcp::Accept()
{
    if(gcfg.ccfg.runningmode == "server" && gcfg.ccfg.protocol == TCP)
    {
        socklen_t size = sizeof(gcfg.scfg.remoteaddr);
        clientfd = accept(gcfg.scfg.sockfd, (sockaddr *)&gcfg.scfg.remoteaddr, &size);
        if(clientfd < 0)
        {
            perror("TCP Establish Failed!");
            return -1;
        }
        std::cout << "TCP Establish Success!" << std::endl;
    }
    return 0;
}

int CalcDelaySockTcp::Send()
{
    int ret = 0;
    char tmpbuf[512];
    memset(sendbuf,1,MESSAGESIZE);
    clock_gettime(CLOCK_REALTIME, &systemts);
    if((ret = send(clientfd, sendbuf, sizeof(sendbuf), 0)) < 0)
    {
        perror("TCP Send Failed!");
        return ret;
    }
    std::cout << "TCP Send Success!" << std::endl;
    return SkRecv(clientfd, tmpbuf, sizeof(tmpbuf), gcfg.scfg.remoteaddr, MSG_ERRQUEUE);
}

int CalcDelaySockTcp::Recv(int flag)
{
    return SkRecv(clientfd, recvbuf, sizeof(recvbuf), gcfg.scfg.remoteaddr, flag);
}

char* CalcDelaySockTcp::GetSendBuf()
{
    return sendbuf;
}

char* CalcDelaySockTcp::GetRecvBuf()
{
    return recvbuf;
}

int CalcDelaySockTcp::Close()
{
    if(gcfg.ccfg.runningmode == "server")
    {
        if(close(clientfd))
        {
            perror("TCP clientfd Close Failed!");
            return -1;
        }
    }

    if(close(gcfg.scfg.sockfd))
    {
        perror("TCP sockfd Close Failed!");
        return -1;
    }

    return 0;
}


}     //  namespace calcdelay