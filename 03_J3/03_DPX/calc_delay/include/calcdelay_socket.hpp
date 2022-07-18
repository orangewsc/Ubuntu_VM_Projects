#ifndef __CALCDELAY_SOCKET_H
#define __CALCDELAY_SOCKET_H


#include "common.h"


namespace calcdelay
{
class CalcDelaySock
{
    public:
        globalconfig    gcfg;
        struct timespec systemts;
        struct timespec hardwarets;
        explicit CalcDelaySock(globalconfig  &gcfg);
        virtual ~CalcDelaySock() = default;
        virtual int Send() = 0;
        virtual int Recv(int flag) = 0;
        virtual int Bind() = 0;
        virtual int Listen() = 0;
        virtual int Connect() = 0;
        virtual int Accept()  = 0;
        virtual int SetSock() = 0;
        virtual int Close()  = 0;
        int64_t     GetDelay();
        virtual char* GetSendBuf() = 0;
        virtual char* GetRecvBuf() = 0; 
        int64_t       TimeSpec2Ns(struct timespec&);
        int         SkRecv(int sockfd, void* buf, int buflen, 
                           struct sockaddr_in addr, int flags);
    private:
        
        int64_t         delay;
};


}  //namespace calcdelay



#endif