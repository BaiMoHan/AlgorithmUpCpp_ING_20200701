#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i; 
	srand((unsigned)time(NULL));	//初始化随机数种子
	for(i=0;i<10;i++)	//生成[10000,60000]内的随机数 
		printf("%d ",(int)(1.0*rand()/RAND_MAX*50000+10000));
	return 0;
 } 
