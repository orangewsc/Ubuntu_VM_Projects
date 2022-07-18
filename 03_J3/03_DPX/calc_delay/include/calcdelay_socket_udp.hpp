#ifndef __CALCDELAY_SOCKET_UDP_H
#define __CALCDELAY_SOCKET_UDP_H



#include <calcdelay_socket.hpp>

namespace calcdelay
{
class CalcDelaySockUdp : public CalcDelaySock
{
public:
    explicit CalcDelaySockUdp(globalconfig  &gcfg);
    ~CalcDelaySockUdp();
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
    char sendbuf[MESSAGESIZE];
    char recvbuf[MESSAGESIZE];
};



#endif





}   // namespace calcdelay