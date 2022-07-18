#include "processfork.h"


int main(int argc,char* argv[])
{
    cout<<"father process name:"<<argv[0]<<endl;

    pid_t pid1,pid2,pid3;
    
    pid1=fork();
    if(0==pid1)
    {
        setproctitle_init(argc,argv,"wscprocess1");
        thread t1(thread_func1);
        pthread_setname_np(t1.native_handle(),"CtApUSBCom");
        t1.join();
        delete[] environ_new;
        exit(1);
    }

    pid2=fork();
    if(0==pid2)
    {
        setproctitle_init(argc,argv,"wscprocess2");
        thread t2(thread_func2);
        pthread_setname_np(t2.native_handle(),"CtApVMS");
        t2.join();
        delete[] environ_new;
        exit(1);
    }

    cout<<"father process PID:"<<getpid()<<endl;

    waitpid(pid1,NULL,0);
    waitpid(pid2,NULL,0);

    return 0;
}
