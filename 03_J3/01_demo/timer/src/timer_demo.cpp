#include <timer_demo.h>


int main()
{
    Sig_config();
    Timer_create();
    Timer_settime();

    while (1)
    {
        cout<<"timer update"<<endl;
        sigsuspend(&sigset_mask);
    }
    
    return 0;
}