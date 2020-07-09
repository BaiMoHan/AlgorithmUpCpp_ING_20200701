//桶排序 
#include<stdio.h>
#define M 50
int main()
{
	int book[M+1];
	int i,x,N;
	for(i=0;i<M+1;i++)
	{
		book[i]=0;//初始化每个数对应的位置为0 
	 } 
	 scanf("%d",&N);
	 for(i=0;i<N;i++)
	 {
	 	scanf("%d",&x);
	 	book[x]++;//对应位置递增计数 
	 }
	 for(i=0;i<M+1;i++)
	 {
	 	while(book[i])//输出被标记的数组 
	 	{
	 		printf("%d ",i);
	 		book[i]--;//输入完一个数字后就计数递减 
		 }
	  } 
	  return 0;
}
