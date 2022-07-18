/** 
 * @FilePath     : /calc_delay/src/calc_delay.cpp
 * @author       : Wang shicheng
 * @Date         : 2022-04-03 15:24:24
 * @LastEditTime : 2022-04-29 15:55:32
 * @LastEditors  : Wang shicheng
 * @description  : 
 * @copyright    : Copyright (c) 2022 hbre&siac
 * @
 */

#include "common.h"
#include "config.hpp"
#include "handle_signal.hpp"
#include "calcdelay_socket.hpp"
#include "calcdelay_socket_tcp.hpp"
#include "calcdelay_socket_udp.hpp"

static struct calcdelay::globalconfig gcfg;

int main(int argc, char *argv[])
{
    struct sockaddr_in localaddr;
    struct sockaddr_in remoteaddr;
    std::shared_ptr<calcdelay::CalcDelaySock> pCalcDelaySock;

    std::shared_ptr<calcdelay::HandleSignal> pHandleSignal=calcdelay::HandleSignal::GetInstance();
    if(pHandleSignal->RegistHandle())
    {
        std::cout << "RegistHandle Failed!" <<std::endl;
    }

    std::shared_ptr<calcdelay::Config> pConfig = calcdelay::Config::GetInstance();
    if(pConfig->ParseCommand(argc, argv))
    {
        return -2;
    }
    pConfig->ShowCfg();

    gcfg.ccfg = pConfig->GetCfg();

    localaddr.sin_family        =   AF_INET;
    localaddr.sin_port          =   htons(gcfg.ccfg.port);
    localaddr.sin_addr.s_addr   =   INADDR_ANY;

    remoteaddr.sin_family        =   AF_INET;
    remoteaddr.sin_port          =   htons(gcfg.ccfg.port);
    remoteaddr.sin_addr.s_addr   =   inet_addr(gcfg.ccfg.remoteIP.c_str());

    gcfg.scfg.localaddr         =   localaddr;
    gcfg.scfg.remoteaddr        =   remoteaddr;

    if(gcfg.ccfg.protocol == TCP)
    {
        while ((gcfg.scfg.sockfd    =   socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        {
            perror("TCP Sock init error!");
            close(gcfg.scfg.sockfd);
            continue;
        }
        std::cout << "TCP Sock Init Success!" << std::endl;

        pCalcDelaySock = std::make_shared<calcdelay::CalcDelaySockTcp>(gcfg);
    }
    else if(gcfg.ccfg.protocol == UDP)
    {
        while ((gcfg.scfg.sockfd    =   socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        {
            perror("UDP Sock init error!");
            close(gcfg.scfg.sockfd);
            continue;
        }
        std::cout << "UDP Sock Init Success!" << std::endl;
        pCalcDelaySock = std::make_shared<calcdelay::CalcDelaySockUdp>(gcfg);
    }

    pCalcDelaySock->SetSock();
    pCalcDelaySock->Bind();
    pCalcDelaySock->Listen();
    pCalcDelaySock->Accept();
    pCalcDelaySock->Connect();

    int num = 0, 
        delaycnt = gcfg.ccfg.transmittime * 1000 / gcfg.ccfg.transmitcycle;
    long long    meandelay = 0;
    while (num < delaycnt)
    {
        pCalcDelaySock->Send();
        meandelay += pCalcDelaySock->GetDelay();
        pCalcDelaySock->Recv(MSG_DONTWAIT);
        usleep(gcfg.ccfg.transmitcycle);
        num++;
    }
    
    std::cout << "meandelay:" << meandelay/delaycnt << std::endl;

    return 0;
}