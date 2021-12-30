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


int UDPInit()
{
    request_addr.sin_family = AF_INET;
	request_addr.sin_port = htons(1111);
	request_addr.sin_addr.s_addr = inet_addr("192.168.2.1");   //windows:servaddr.sin_addr.S_un.S_addr  unix:servaddr.sin_addr.s_addr = inet_addr("172.31.1.48);


    response_addr.sin_family = AF_INET;
	response_addr.sin_port = htons(2222);
	response_addr.sin_addr.s_addr = inet_addr("192.168.2.10");   //windows:servaddr.sin_addr.S_un.S_addr  unix:servaddr.sin_addr.s_addr = inet_addr("172.31.1.48);
    
    local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(4444);
	local_addr.sin_addr.s_addr = inet_addr("192.168.2.1");   //windows:servaddr.sin_addr.S_un.S_addr  unix:servaddr.sin_addr.s_addr = inet_addr("172.31.1.48);

	//init 
    socket_client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	while (socket_client < 0)
	{
        perror("socket_client init error");
		close(socket_client);        // ***Wimsock: closesocket(socket_client); Unix: close(socket_client);
		socket_client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		continue;
	}
    cout<<"socket_client init sucessful!"<<endl;

	socket_server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	while (socket_server < 0)
	{
        perror("socket_server init error");
		close(socket_server);        // ***Wimsock: closesocket(socket_server); Unix: close(socket_server);
		socket_server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		continue;
	}
    cout<<"socket_server init sucessful!"<<endl;

	//绑定本地地址到socket
	if (::bind(socket_client, (sockaddr*)&request_addr, sizeof(request_addr))<0)
	{
		perror("socket_client bind error");
	}

	if (::bind(socket_server, (sockaddr*)&local_addr, sizeof(local_addr))<0)
	{
		perror("socket_server bind error");
	}

	return 0;
}

int Sendto(const char* sendbuf)
{
	while (true)
	{
		sleep(1);
		if(sendto(socket_client,sendbuf,56,0,(sockaddr*)&response_addr, sizeof(response_addr))<0)
		{
			perror("send buf error");
			cout<<"send buf error"<<endl;
		}
		cout<<"send buf successful!"<<endl;
	}
	return 0;
}


int Recvfrom(char recvbuf[10])
{
	int len=sizeof(sockaddr_in);
	while(true)
	{
		sleep(1);
		if(recvfrom(socket_server,recvbuf,10,0,(sockaddr*)&remote_addr,(socklen_t*)&len)<0)
		{
			perror("recv buf error");
		}
		cout<<"recv data:";
		for(int i=0;i<10;i++)
		{
			printf("%d ",recvbuf[i]);
		}
		cout<<endl;
	}
	return 0;
}

#endif