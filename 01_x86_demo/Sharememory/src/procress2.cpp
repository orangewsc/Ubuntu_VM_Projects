#include "include.h"

int main()
{
    process_start_read(p_shm_msg);
    if(p_shm_msg)
    {
        cout<<"share addr:"<<p_shm_msg<<endl;
    }
    else
    {
        perror("p_shm_msg error");
    }

    while (1)
    {
        sem_wait(sem_read);
        sem_wait(sem_mutex);

        int n       = p_shm_msg->msgnum;
        char *p     = p_shm_msg->data;
        sem_post(sem_mutex);
        if(sem_post(sem_write))
        {
            perror("process2 sem_post error");
        }
        
        cout<<"[read msg: "<<n<<"] :"<< p <<" successful!"<<endl;
        // printf("[read msg:%d]:%s\n",n,p);
        // cout<<p_shm_msg->data<<endl;
        sleep(1);
    }
    exit(0);
}