#include<stdio.h>
int h[101];//用来存放堆的数组
int n;//堆中元素的个数
void swap(int x,int y);//将结点x与结点y进行交换
void siftdown(int i);//从结点i开始向下调整 
void swap(int x,int y);//一开始设置了全局数组，此处不用传递指针 
void creat();//创建堆的函数
int deletemax();//删除堆顶最小的元素，并返回其值 
int main()
{
	int i,num;//此处必须要一个num,因为后面n的个数不断改变，但是输出要输出n个数 
	//读入要排序的个数
	scanf("%d",&num);
	//读取输入的数字 
	for(i=1;i<=num;i++)
	{
		scanf("%d",&h[i]);
	 } 
	 n=num;
	 //建堆
	 creat();
	 //删除顶部元素，连续删除n次，其实输出的就是从小到大输出
	/************打印建堆的结果**************
	 for(i=1;i<=num;i++)
	 	printf("%d ",h[i]);
	*****************************************/ 
	printf("\n");
	 for(i=1;i<=num;i++)
	 	printf("%d ",deletemax());
		
	return 0; 
 } 
void swap(int x,int y)//删除最大的元素，并返回最大值 
{
	int temp;//临时变量交换
	temp=h[x];
	h[x]=h[y]; 
	h[y]=temp; 
	/*不借助中间变量的交换法 
	h[x]=x+y;
	h[y]=h[x]-h[y];
	h[x]=h[x]-h[y]; 
	该种交换方法可能带来两个数相加超过了数据类型的最大值
	还可以用异或操作来实现不借助中间变量的两数交换
	*/ 
	return ;
 } 
 /*void siftdown(int i)原文写法 
 {
 	int t,flag=0;
 	while(i*2<=n&&flag==0)
 	{
 		if(h[i]>h[i*2])
 			t=i*2;
 		else
 			t=i;
 		if(i*2+1<=n)
 		{
 			if(h[t]>h[i*2+1])
 				t=i*2+1;
		 }
		 if(i!=t)
		 {
		 	swap(t,i);
		 	i=t;
		 }
		 else
		 	flag=1;
	 }
	 return ;
  } 
*/ void siftdown(int i)
 {
 	int t,flag=0;//t用来存放中间的编号，flag用来标记是否处于合适位置 
 	while(i*2<=n && flag==0)
	 {
	 	t=i;//t用来存储操作后的编号，如果没有发生改变，则说明该结点已处于合适的位置 
	 	//首先判断是否要与左儿子交换,进入循环后左儿子是一定有的
		 if(h[i]>h[2*i])//比左儿子大则需要交换
		 {
			 t=2*i;//记录待交换的编号，此时不确定是否有右儿子，不可交换 
		  } 
		//判断是否存在右儿子
		if(2*i+1<=n)
		{
			//右儿子存在判断是否需要交换
			if(h[t]>h[2*i+1]) 
			{
				t=2*i+1;//记录待交换的结点编号 
			}
		 } 
		 if(t!=i)//t!=i说明发生了交换带来了编号改变，可能需要继续向下交换
		 {
		 	swap(i,t);//与两儿子比对后方可交换 
		 	i=t;//确定最后的新的编号 
		  } 
		  else
		  	flag=1;//i与t的值相同说明此轮无交换，已经处于合适的根结点了，更新标记 
	  } 
	  return ; 
 }//
 void creat()
 {
 	//创建堆，从最后一个非叶结点依次向下调整
 	int i;
	 for(i=n/2;i>=1;i--)
	 {
	 	siftdown(i);//每个子树调整好，最后一棵树也就成了最小堆 
	  } 
	  return ;
 }
 int deletemax()
 {
 	int t;//临时存放返回值
	t=h[1];
	h[1]=h[n];//将末尾值赋值给堆顶
	n--;//删除元素带来元素的减少
	siftdown(1);//从堆顶开始向下调整
	return t;//返回删除的最大值 
 } 
