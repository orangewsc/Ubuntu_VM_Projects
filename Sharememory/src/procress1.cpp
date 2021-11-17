#include "include.h"



int main()
{
    process_start_write(p_shm_msg);
    if(p_shm_msg)
    {
        cout<<"share addr:"<<p_shm_msg<<endl;
    }
    else
    {
        perror("p_shm_msg error");
    }
    for(int i=0;i<25;i++)
    {
        p_shm_msg->data[i]=i+'0';
    }

    while (1)
    {
        static int index =0;
        index++;
        sem_wait(sem_write);
        sem_wait(sem_mutex);

        p_shm_msg->msgnum++;
        // p_shm_msg->msg.clear();
        string str= "Msg"+to_string(index);
        p_shm_msg->msg=str;
        sem_post(sem_mutex);
        sem_post(sem_read);

        cout<<"[write msg "<<p_shm_msg->msgnum<<"] :"<<p_shm_msg->msg<<"successful!"<<endl;
        cout<<p_shm_msg->data<<endl;

        sleep(1);
    }

    exit(0);
}