
#ifndef __CALCDELAY_SOCKET_TCP_H
#define __CALCDELAY_SOCKET_TCP_H

#include "calcdelay_socket.hpp"

namespace calcdelay
{

class CalcDelaySockTcp : public CalcDelaySock
{
    public:
        explicit CalcDelaySockTcp(globalconfig  &gcfg);
        ~CalcDelaySockTcp();
        int Send()              override;
        int Recv(int flag)      override;
        int Bind()              override;
        int Listen()            override;
        int Connect()           override;
        int Accept()            override;
        int SetSock()           override;
        int Close()             override;
        char* GetSendBuf()      override;
        char* GetRecvBuf()      override;     

    private:
        int  clientfd;
        char sendbuf[MESSAGESIZE];
        char recvbuf[MESSAGESIZE];
};



}  //namespace calcdelay


#endif