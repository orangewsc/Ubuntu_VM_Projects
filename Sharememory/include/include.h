#ifndef __INCLUDE_H
#define __INCLUDE_H


#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <sys/mman.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <error.h>
#include <memory>
#include <stdio.h>
#include <string>


using namespace std;

#pragma pack(1)

typedef struct _shm_msg
{
    int     msgnum;
    string  msg;
    char    data[25];
}_shm_msg;

extern    sem_t   *sem_mutex;
extern    sem_t   *sem_read; 
extern    sem_t   *sem_write;
extern    int     shm_fd;
// extern shared_ptr<_shm_msg> p_shm_msg;
extern _shm_msg *p_shm_msg;
extern void process_start_write(_shm_msg* &shm_msg);
extern void process_start_read(_shm_msg* &shm_msg);







#endif