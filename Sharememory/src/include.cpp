#include "include.h"


// shared_ptr<_shm_msg> p_shm_msg(new _shm_msg);
// shared_ptr<_shm_msg> p_shm_msg = make_shared<_shm_msg>();
int     shm_fd;
sem_t   *sem_mutex;
sem_t   *sem_read; 
sem_t   *sem_write;
_shm_msg *p_shm_msg = new _shm_msg;
void process_start_write(_shm_msg* &p_shm_msg)
{
    shm_unlink("shm_test");
    shm_fd     =   shm_open("shm_test",O_RDWR | O_CREAT , S_IRUSR | S_IWUSR| S_IWGRP | S_IRGRP | S_IROTH|S_IWOTH);
    if(shm_fd>0)
    {
        cout<<"shm_fd open successful!"<< shm_fd<<endl;
    }
    else{
        perror("shm_fd open error");
    }
    
    p_shm_msg=(_shm_msg*)mmap(NULL,sizeof(_shm_msg), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if(p_shm_msg)
    {
        cout<<"p_shm_msg open successful!"<< p_shm_msg<<endl;
    }
    else{
        perror("p_shm_msg open error");
    }
    ftruncate(shm_fd,sizeof(_shm_msg));
    close(shm_fd);

    sem_mutex  =   sem_open("sem_mutex",O_RDWR | O_CREAT ,  S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP| S_IROTH|S_IWOTH,1);
    if(sem_mutex)
    {
        cout<<"sem_mutex open successful!" << sem_mutex<<endl;
    }
    else{
        perror("sem_mutex open error");
    }

    sem_read   =   sem_open("sem_read",O_RDWR | O_CREAT,  S_IRUSR | S_IWUSR| S_IWGRP | S_IRGRP| S_IROTH|S_IWOTH,6);
    if(sem_read)
    {
        cout<<"sem_read open successful!"<<sem_read<<endl;
    }
    else{
        perror("sem_read open error");
    }

    sem_write  =   sem_open("sem_write",O_RDWR | O_CREAT, S_IRUSR | S_IWUSR| S_IWGRP | S_IRGRP| S_IROTH|S_IWOTH,5);
    if(sem_write)
    {
        cout<<"sem_write open successful!"<<sem_write<<endl;
    }
    else{
        perror("sem_write open error");
    }
}


void process_start_read(_shm_msg* &p_shm_msg)
{
    shm_fd     =   shm_open("shm_test",O_RDWR | O_CREAT , S_IRUSR | S_IWUSR| S_IWGRP | S_IRGRP| S_IROTH|S_IWOTH);
    if(shm_fd>0)
    {
        cout<<"shm_fd open successful!"<< shm_fd<<endl;
    }
    else{
        perror("shm_fd open error");
    }

    p_shm_msg  =  (_shm_msg*)mmap(NULL,sizeof(_shm_msg), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if(p_shm_msg)
    {
        cout<<"p_shm_msg open successful!"<< p_shm_msg<<endl;
    }
    else{
        perror("p_shm_msg open error");
    }
    ftruncate(shm_fd,sizeof(_shm_msg));
    close(shm_fd);

    sem_mutex  =   sem_open("sem_mutex",0);//O_RDWR | O_CREAT ,  S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP| S_IROTH|S_IWOTH ,1);
    if(sem_mutex)
    {
        cout<<"sem_mutex open successful!" << sem_mutex<<endl;
    }
    else{
        perror("sem_mutex open error");
    }

    sem_read   =   sem_open("sem_read",0);//O_RDWR | O_CREAT,  S_IRUSR | S_IWUSR| S_IWGRP | S_IRGRP| S_IROTH|S_IWOTH,5);
    if(sem_read)
    {
        cout<<"sem_read open successful!"<<sem_read<<endl;
    }
    else{
        perror("sem_read open error");
    }

    sem_write  =   sem_open("sem_write",0);//O_RDWR | O_CREAT, S_IRUSR | S_IWUSR| S_IWGRP | S_IRGRP| S_IROTH|S_IWOTH,1);
    if(sem_write)
    {
        cout<<"sem_write open successful!"<<sem_write<<endl;
    }
    else{
        perror("sem_write open error");
    }


    sem_unlink("sem_mutex");
    sem_unlink("sem_read");
    sem_unlink("sem_write");
    shm_unlink("shm_test");
}