#ifndef _Socket_Status_H
#define _Socket_Status_H


#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>
#include <signal.h>
#include <errno.h>
#include <netinet/tcp.h>
#include <sys/select.h>
#include <iostream>
#include <stdio.h>
#include <memory>
#include <arpa/inet.h>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <thread>
#include <mutex>

using namespace std;

int 				socket_client, socket_server;
struct sockaddr_in  request_addr,response_addr,
					local_addr,remote_addr;






#endif