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
#include <sys/prctl.h>
#include <pthread.h>
#include <thread>
#include <sys/wait.h>
#include <string.h>


void thread_func3()
{
	int i=0;
	while(1)
	{
		sleep(3);
		i++;
		cout<<"thread_func3 run "<<i<<" times"<<endl;
	}
}