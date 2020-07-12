#include<stdio.h>
int binarysearch(int a[],int left,int right,int x);
int main()
{
	const int n=10;
	int a[n]={1,2,3,4,5,8,34,49,90,190};//此处为严格递增序列 
	//在顺序表中查找6和9 
	printf("%d %d",binarysearch(a,0,n-1,49),binarysearch(a,0,n-1,9));
	return 0; 
}

//二分搜索，传入参数顺序表，左端点，右端点，待查找的元素 
int binarysearch(int a[],int left,int right,int x)
{
	int mid;//中位数 
	while(left<=right)//推出条件为left>right 
	{
		//每一次查找都从当前区间的中间处开始 
		mid=left+(right-left)/2;//防御性编程，防止left+right造成int型溢出
		if(a[mid]==x)
			return mid;//找到x，返回下标
		else if(a[mid]>x)//递增序列从大于开始
			right=mid-1;//中间位置大于待查值，说明如果存在则在中点的左边
		else
			left=mid+1;//说明如果存在，则在区间的右边 
	}
	return -1;//上面退出循环说明没找到 
}
