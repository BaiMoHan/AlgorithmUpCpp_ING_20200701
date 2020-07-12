#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i;			//计数器变量 
	srand((unsigned)time(NULL));//初始化随机数种子 
	for(i=0;i<10;i++)
		printf("%d ",rand());	//随机打印十个随机数
	return 0; 
 } 
