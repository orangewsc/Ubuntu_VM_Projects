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
#include <sys/prctl.h>
#include <pthread.h>
#include <thread>
#include <sys/wait.h>
#include <string.h>



using namespace std;

#pragma pack(1)

void thread_func1()
{
	int i=0;
	while(1)
	{
		sleep(1);
		i++;
		cout<<"thread_func1 run "<<i<<" times"<<endl;
	}
}

void thread_func2()
{
	int i=0;
	while(1)
	{
		sleep(2);
		i++;
		cout<<"thread_func2 run "<<i<<" times"<<endl;
	}
}

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

extern char** environ;
static char** argv_bkp;
static char* argv_last_bkp;
char *environ_new;

void setproctitle_init(int argc,char*argv[],char* process_newname)
{
	size_t size=0;

	// 统计所有 environ 环境变量的长度(+1 是表示每个字符串后的 '\0')
	for(int i=0;environ[i];i++)
	{
		size+=strlen(environ[i])+1;
	}

	// 重新分配一段内存，待会用来保存 environ 指向的环境变量
	environ_new=new char[size];

	argv_bkp=argv;
	argv_last_bkp=argv_bkp[0];

	// 遍历 argv，完成后指向 argv 最后一个参数的 '\0' 的下一个位置，也就是 envp[0] 的地址
	for(int i=0;argv_bkp[i];i++)
	{
		if(argv_last_bkp==argv_bkp[i])
		{
			argv_last_bkp=argv_bkp[i]+strlen(argv_bkp[i])+1;
		}
	}

	for(int i=0;environ[i];i++)
	{
		if(argv_last_bkp==environ[i])
		{
			// 包括 '\0'
			size=strlen(environ[i])+1;

			//  接着往后递进, 经过每一个环境变量
			argv_last_bkp=environ[i]+size;

			// 拷贝每一个 环境变量到上面刚申请的新内存中
			strncpy(environ_new,environ[i],size);

			// 修改 environ[i] 指向这块新的内存地址（避免后续修改 argv[0] 造成覆盖)
			environ[i]=environ_new;

			// 新内存指针向后移动，成为下一轮 environ[i+1] 的值
			environ_new+=size;
		}
	}

	// 指针往前移 1 个字节，指向 最后一个环境变量的 '\0' 位置
	argv_last_bkp--;

	// 设置 argv[1] = NULL 通常不必要，加上更安全
	argv_bkp[1]=NULL;

	//最初 argv + envp 所有字符串的长度, 拷贝新进程名到 argv[0]
	strncpy(argv_bkp[0],process_newname,argv_last_bkp-argv_bkp[0]);

	prctl(PR_SET_NAME,process_newname);
}


#endif
