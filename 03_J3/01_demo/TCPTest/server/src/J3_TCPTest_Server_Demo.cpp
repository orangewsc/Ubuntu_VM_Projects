#include <J3_TCPTest_Server_Demo.h>



#define TOS 17
int main()
{
	int tos = TOS;
    
    local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(1234);
	local_addr.sin_addr.s_addr = INADDR_ANY;   //windows:servaddr.sin_addr.S_un.S_addr  unix:servaddr.sin_addr.s_addr = inet_addr("172.31.1.48);


	slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten <0)
	{
		printf("socket error !");
		return -1;
	}

	// set IP_TOS
	// if(setsockopt(slisten,SOL_IP,IP_TOS,&tos,sizeof(tos))<0)
	// {
	// 	perror("getsockopt(IP_TOS) failed:");
	// }

	if (bind(slisten, (sockaddr *)&local_addr, sizeof(local_addr)) <0)
	{
		printf("bind error !");
		return -1;
	}

	if (listen(slisten, 10) <0)
	{
		printf("listen error !");
		return -1;
	}

	int nAddrlen = sizeof(remote_addr);
	
	socket_client = accept(slisten, (sockaddr *)&remote_addr, (socklen_t *)&nAddrlen);

	printf("Established Successful!\n");

	fcntl(socket_client,F_SETFD,FD_CLOEXEC);
	
	if(setsockopt(socket_client,SOL_IP,IP_TOS,&tos,sizeof(tos))<0)
	{
		perror("setsockopt(IP_TOS) failed:");
	}

	if(setsockopt(socket_client,SOL_IPV6,IPV6_TCLASS,&tos,sizeof(tos))<0)
	{
		perror("setsockopt(SOL_IPV6) failed:");
	}

	tos=1;
	if(setsockopt(socket_client,SOL_TCP,TCP_NODELAY,&tos,sizeof(tos))<0)
	{
		perror("setsockopt(SOL_TCP) failed:");
	}

	char buf[10]= "123456789";
	
	while(1)
	{
		if (send(socket_client, buf, sizeof(buf), 0) <= 0)
		{
			cout<<"send error !!"<<endl;
			return -2;
		}
		sleep(1);
	}

	close(socket_client);
	return 0;
}