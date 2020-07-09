//quick排序
#include<stdio.h>
#define N 100
int count[N+1],n;//定义全局变量，避免子函数定义时的数组指针
void quicksort(int left,int right);
//第一个参数是左哨兵，第二个参数是右哨兵 
int main()
{
	int i;
	scanf("%d",&n);//读取这批数字的个数
	for(i=1;i<n+1;i++)
	{
		scanf("%d",&count[i]);
	 } 
	 quicksort(1,n);
	for(i=1;i<n+1;i++)
	{
		printf("%d ",count[i]);
	}
	return 0;
 } 
 void quicksort(int left,int right)
 {
 	int i,j,t,pivot;//定义左右哨兵 

 	if(left>right)
	 //排序好的末态就是两个指针位置重合，但下一次会继续移动，造成i>j 
 		return ;
 		
 	i=left;
 	j=right;
	pivot=count[right];//选取最右边的数作为基准
 	
 	while(i!=j)
 	{
	 	while(count[i]<=pivot&&i<j)
		 //顺序很重要，定右边为基准，就先从寻找左边比pivot大的数 
		 i++;		
 		while(count[j]>=pivot&&i<j)//寻找右边比pivot小的数 
		 j--;
			
		
		
		if(i<j)
		{
			t=count[i];
			count[i]=count[j];
			count[j]=t; 
		}	
	  } 
	  count[right]=count[i];
	  count[i]=pivot;
	  quicksort(left,i-1);
	  //继续以这种方法处理右边的，递归 
	  quicksort(i+1,right);
	  //继续以这种方法处理左边的，递归 	
 }
