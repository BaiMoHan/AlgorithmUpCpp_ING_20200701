#include<stdio.h>
int h[101],n;//设置数组存放完全二叉树，n为堆中元素个数
void swap(int x,int y);//结点x与结点y进行交换
void siftdown(int i);//从结点i开始向下调整
void creat();//建立堆的函数 
void heapsort();//堆排序函数
int main()
{
	int num,i;
	//读取堆中元素个数
	 scanf("%d",&num);
	 //读入堆中元素
	 for(i=1;i<=num;i++)
	 	scanf("%d",&h[i]);
	n=num;//元素的个数会后面操作改变,num当作循环变量用 
	creat();//创建堆 
	//堆排序
	heapsort();
	//输出排序后的值
	for(i=1;i<=num;i++)
		printf("%d ",h[i]); 
	 return 0;
 } 
 void swap(int x,int y)
 {
 	int temp;
 	temp=h[x];
 	h[x]=h[y];
 	h[y]=temp;
  } 
  void siftdown(int i)//此处的向下调整函数是为了建立最大堆 
  {
  	int t,flag=0;//t用来确定是否需要交换，flag用来标记是否处于合适的根结点处 
    while(i*2<=n && 0==flag)
	{
		t=i;//初始赋值相同的编号 
		//能进入循环说明左儿子一定存在，先于左儿子比较
		if(h[i]<h[2*i])
		{
			t=2*i;//待交换的结点编号 
		 } 
		//判断是否有右儿子
		if(2*i+1<=n)
		{
			//与右儿子进行比较
			if(h[t]<h[i*2+1]) 
			{
				t=i*2+1;//待交换的结点编号 
			 } 
		 } 
		 if(t!=i)//不相等说明需要交换
		 {
		 	swap(i,t);//交换两节点
			i=t;//交换后，向下调整的元素的编号也变了 
		  } 
		  else
		  	flag=1;//不需要交换则说明该元素已经处于合适的根结点处 
	 } 
	 return ; 
  }
  void heapsort()
  {
  	//堆排序，每次将堆顶与最后一个数交换，再向下调整
	  while(n>1)//注意此处，剩余最后一个数放到堆顶自动是最小的，循环条件为只剩一个元素 
	  {
	  	swap(1,n);
	  	n--;
	  	siftdown(1);
	   } 
	   return ;
   } 
   void creat()
   {
   	//建立堆的函数，每个子树满足最大堆，从而整棵树也满足
	   int i;
	   for(i=n/2;i>=1;i--)
	   {
	   		siftdown(i);
		} 
		return ;
   }
  
  
