//用数组模拟链表
#include<stdio.h>
#define N 101
int main()
{
	//设置一个存放数据的数组和一个指针作用的数组 
	int data[N],right[N],n,i,a;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&data[i]);
		if(i!=n)//初始化指针作用的数组right 
		{
			right[i]=i+1;
		 } 
		else
		{
			right[i]=0;//末尾标记为0,类似NULL 
		} 
	}
	printf("插入数字之前:\n");
	i=1;//从头遍历 
	while(i!=0)
	{
		printf("%d ",data[i]);
		i=right[i]; 
	 } 
	 printf("\n请输入插入的新的数字");
	 scanf("%d",&a);
	 //进行数字的插入 
	 i=1;//从头遍历 
	 n++;
	 while(i!=0)//遍历结束条件为right[i]=0 
	 {
	 	if(data[right[i]]>a)//如果当前结点的下一个结点大于插入的数，就插入 
	 	{
	 		data[n]=a;
	 		right[n]=right[i];
	 		right[i]=n;
	 		break;
		 }
		 else if(right[i]==0)
		 {
		 	data[n]=a;
		 	right[n]=0;
		 	right[i]=n;
		 	break;
		 } 
		 i=right[i];
	 }
	 i=1;//从头遍历 
	while(i!=0)
	{
		printf("%d ",data[i]);
		i=right[i];
	 } 
 } 
