#include <stdio.h>
#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void threadFunc1(int num)
{
	for (int i = 0; i < num;i++)
	{
		sleep(1);
		cout << "线程1:["<<std::this_thread::get_id()<<"]运行第[" << i << "]次"<< endl;
	}
}


void threadFunc2()
{
	cout << "线程2:["<<std::this_thread::get_id()<<"]直接运行了。" << endl;
}
