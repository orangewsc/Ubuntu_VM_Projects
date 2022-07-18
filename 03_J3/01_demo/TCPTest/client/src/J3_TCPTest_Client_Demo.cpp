#include <J3_TCPTest_Client_Demo.h>

int main()
{
    request_addr.sin_family = AF_INET;
	request_addr.sin_port = htons(1234);
	request_addr.sin_addr.s_addr = inet_addr("192.168.3.70");   //windows:servaddr.sin_addr.S_un.S_addr  unix:servaddr.sin_addr.s_addr = inet_addr("172.31.1.48);

	//init 
    socket_client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	while (socket_client < 0)
	{
        perror("socket_client init error");
		close(socket_client);        // ***Wimsock: closesocket(socket_client); Unix: close(socket_client);
		socket_client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		continue;
	}
    cout<<"socket_client init sucessful!"<<endl;


	while (connect(socket_client,(struct sockaddr*)&request_addr,sizeof(request_addr)) < 0)
	{
		printf("!!!!!!!!!!!!!!!!!!!    Connect Failed!    !!!!!!!!!!!!!!!!!!! \n");
	}

	cout<<"connect successful!!"<<endl;

	char buf[10];
	while(1)
	{
        if (recv(socket_client, buf, sizeof(buf), 0) <= 0)
		{
			cout<<"recv error !!"<<endl;
			return -2;
		}
        cout<<"buf[]:"<<buf<<endl;
	}

	return 0;
}
