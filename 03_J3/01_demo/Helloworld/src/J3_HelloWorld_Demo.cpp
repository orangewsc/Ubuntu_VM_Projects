#include <J3_HelloWorld_Demo.h>

int main()
{
    std::cout<<"==================== J3_HelloWorld_Demo: Hello World Start! ===================="<<std::endl;
    thread t1(threadFunc1,10);
    thread t2(threadFunc2);

    t1.join();
    t2.join();

    std::cout<<"==================== J3_HelloWorld_Demo: Hello World End! ===================="<<std::endl;
    return 0;
}