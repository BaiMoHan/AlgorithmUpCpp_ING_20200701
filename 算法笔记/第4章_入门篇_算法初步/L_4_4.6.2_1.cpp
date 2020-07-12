//递归实现归并排序
#include<stdio.h>
const int maxn=100;
void merge(int a[],int L1,int R1,int L2,int R2);//将两个有序序列合并为一个有序序列
void mergesort(int a[],int left,int right);//归并排序函数
int main()
{
	int a[maxn]={0,5,59,23,54,16,3,28,36,86,2,9,7};
	mergesort(a,0,12) ;
	for(int i=0;i<13;i++)
		printf("%d ",a[i]);
	return 0;
 } 
void merge(int a[],int L1,int R1,int L2,int R2)
{
	//将数组a的[L1,R1]与[L2,R2]区间合并为有序区间，此处L2=R1+1
	int i=L1,j=L2;	//i指向a[L1]，j指向a[L2]
	int temp[maxn],index=0;	//临时存放数组，与临时指引
	while(i<=R1 && j<=R2)
	{
		if(a[i]<a[j])		//a[i]更小 
			temp[index++]=a[i++];//将a[i]加入到temp中 
		else				//a[j]更小 
			temp[index++]=a[j++];//将a[j]加入到temp中 
	 } 
	 //将未合并完的区间剩下的元素存入temp中
	 while(i<=R1)//将[L1,R1]中剩余元素加入temp中 
	 	temp[index++]=a[i++]; 
	 while(j<=R2)//将[L2,R2]中剩余元素加入temp中
	 	temp[index++]=a[j++];
	 //将临时数组的值重新赋值给原数组
	 for(i=0;i<index;i++)
	 	a[L1+i]=temp[i]; //注意此处数组a是从a[L1]开始的，不是a[0] 
} 
void mergesort(int a[],int left,int right)
{
	//将a数组[left,right]区间进行归并排序
	int mid;	//取区间中点
	if(left<right)//当left==right的时候，说明只剩一个元素了 
	{
		mid=left+(right-left)/2;	//区间分组
		mergesort(a,left,mid);//递归，将[left,right]区间归并排序
		mergesort(a,mid+1,right);//递归，将[mid+1,right]区间归并排序
		merge(a,left,mid,mid+1,right);//将左区间和右区间合并 
	}
	 
}
