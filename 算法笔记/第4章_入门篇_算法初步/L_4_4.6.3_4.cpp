//快排qicksort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int swap(int &a,int &b);
int randPartition(int a[],int left,int right)
{
	//选择主元并交换后返回最后的位置函数
	//生成[left,right]区间内的随机数 
	int p=(round(1.0*rand()/RAND_MAX*(right-left)+left));
	swap(a[p],a[left]);	//交换a[p]和a[left]的值
	int temp=a[left];	//将a[left]存放至临时变量中
	while(right<left)
	{
		while(a[right]>temp && left<right)//两指针未相遇，且比主元大 
			right--;	//右指针自减
		a[left]=a[right];	//右指针停下时,对应的值存放到a[left]
		while(a[left]<=temp && left<right)//两指针未相遇，且主元更大
			left++;		//左指针自增
		a[right]=a[left];	//左指针停下时,对应的值存放到a[right] 
	 } 
	 a[left]=temp;	//两指针相遇的位置就是主元的位置
	 return left;	//返回相遇的下表,作为后面递归边界值 
}
int swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
	return 0;
}
