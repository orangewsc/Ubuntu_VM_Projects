#include <J3_UDPTest_Server_Demo.h>


unsigned  char sendbuf[10] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
					0x07, 0x08, 0x09, 0x10};


char recvbuf[56];
int main()
{
    std::cout<<"==================== J3_UDPTest_Client_Demo Start! ===================="<<std::endl;

    UDPInit();
    
    thread t1(Sendto,(char*)sendbuf);
    thread t2(Recvfrom,(char*)recvbuf);

    t1.join();
    t2.join();

    std::cout<<"====================  J3_UDPTest_Client_Demo End!  ===================="<<std::endl;
    return 0;
}