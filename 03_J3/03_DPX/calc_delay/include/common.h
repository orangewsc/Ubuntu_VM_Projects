#ifndef __INCLUDE_H
#define __INCLUDE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
#include <getopt.h>
#include <memory>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <time.h>
#include <poll.h>
#include <linux/net_tstamp.h>
#include <sys/ioctl.h>
#include <linux/sockios.h>


namespace calcdelay{

#define     TCP         "TCP"
#define     UDP         "UDP"
#define     HARDWARESTR  "HARDWARE"
#define     SOFTWARESTR  "SOFTWARE"

#define     MESSAGESIZE 1460    //bytes
#define     kNsInSec    1000000000
#define     sk_events   POLLPRI
#define     sk_revents  POLLPRI

enum
{
    HARDWARE,
    SOFTWARE
};

struct commonconfig
{
    std::string     nicdevice;
    std::string     progname;
    std::string     runningmode;
    std::string     protocol;
    std::string     remoteIP;
    std::string     timestamping;
    std::string     version;
    uint32_t        port;
    uint16_t        transmitcycle;
    uint16_t        transmittime;
    uint16_t        messagesize;
    bool            printflag;
    uint8_t         tos;
};

struct sockconfig
{
    int     sockfd;
    struct sockaddr_in remoteaddr;
    struct sockaddr_in localaddr;
};

struct globalconfig
{
    commonconfig    ccfg;
    sockconfig      scfg;
};

}  //namespace calcdelay

#endif