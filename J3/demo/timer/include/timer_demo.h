#include <stdio.h>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <signal.h>


using namespace std;

#define SIGRTIMINAL 2
#define PERIOD 2000

timer_t timerid;
struct sigevent evp;
sigset_t sigset_mask,sigset_old;
struct sigaction act;


void handler(int sig)
{
	printf("SIGRTIMINAL handler!\n");
}

void Sig_config()
{
	sigemptyset(&sigset_mask);
	sigaddset(&sigset_mask,SIGRTIMINAL);
	sigdelset(&sigset_mask,SIGRTIMINAL);
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	sigaction(SIGRTIMINAL,&act,0);
}

void Timer_create()
{
	memset(&evp,0,sizeof(struct sigevent));
	evp.sigev_signo = SIGRTIMINAL;
	evp.sigev_notify = SIGEV_SIGNAL;

	if(timer_create(CLOCK_REALTIME,&evp,&timerid)==-1)
	{
		perror("fail to timer_create");
		exit(-1);
	}
}

void Timer_settime()
{
	struct itimerspec it;
	it.it_interval.tv_nsec=1000000*(PERIOD%1000);
	it.it_interval.tv_sec=PERIOD/1000;
	it.it_value.tv_nsec=10;
	it.it_value.tv_sec=0;

	if(timer_settime(timerid,0,&it,0)==-1)
	{
		perror("fail to timer_settime");
		exit(-1);
	}
}







