#ifndef __HANDLE_SIGNAL_H
#define __HANDLE_SIHNAL_H
#include "common.h"

namespace calcdelay
{
class HandleSignal
{
    private:
        HandleSignal(){}
        static std::shared_ptr<HandleSignal> p;
        static void HandleSignalFunc(int signal);
    public:
        static std::shared_ptr<HandleSignal> GetInstance();
        int RegistHandle();
        HandleSignal(const HandleSignal &) = delete;
        HandleSignal& operator=(const HandleSignal &)=delete;
};

std::shared_ptr<HandleSignal> HandleSignal::p(new HandleSignal);
std::shared_ptr<HandleSignal> HandleSignal::GetInstance()
{
    return p;
}

void HandleSignal::HandleSignalFunc(int signal)
{
    std::cout<< "Program aborted by SIGNAL: "<< signal <<std::endl;
    exit(-1);
}


int HandleSignal::RegistHandle()
{
    if(SIG_ERR == signal(SIGINT, HandleSignalFunc))
    {
        perror("cannot handle SIGINT");
        return -10;
    }

    if(SIG_ERR == signal(SIGQUIT, HandleSignalFunc))
    {
        perror("cannot handle SIGQUIT");
        return -11;
    }

    if(SIG_ERR == signal(SIGTERM, HandleSignalFunc))
    {
        perror("cannot handle SIGTERM");
        return -12;
    }

    if(SIG_ERR == signal(SIGHUP, HandleSignalFunc))
    {
        perror("cannot handle SIGHUP");
        return -13;
    }

    return 0;
}

}//namespace calcdelay





#endif