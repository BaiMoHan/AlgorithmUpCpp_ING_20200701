#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//生成指定范围区间的随机数
int main()
{
	int i;	//计数器变量 
	srand((unsigned)time(NULL));	//初始化随机数种子
	//rand()%(b-a+1)的范围是[0.b-a]
	//rand()%(b-a+1)+a的范围是[a,b]
	for(i=0;i<10;i++)
		printf("%d ",rand()%2);	//生成[0,1]区间的随机数
	printf("\n");
	for(i=0;i<10;i++)
		printf("%d ",rand()%3+9);//生成[9,11]区间的随机数 
	return 0; 
 } 
