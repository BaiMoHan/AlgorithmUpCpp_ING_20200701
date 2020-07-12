//求序列中第一个大于等于x的数，二分查找
int lower_bound(int a[],int left,int right,int n)
{
	//二分上下界为左闭右闭区间，传入的初值为0-n，包括n
	int mid;	//mid为left和right的中点
	while(left<right)//注意此处无等于号，left==right即为找到的位置 
	{
		mid=left+(right-left)/2;//防御性编程，取中点
		if(a[mid]>=x)		//中间的数大于等于左边 
		{		 
			right=mid;		//往左区间[left,mid]查找,注意此时不需要mid-1 
		} 
		else 
		{
			left=mid+1;		//区间左端点依旧为mid+1 
		 } 
	 } 
	 return left;			//left==right即为夹出来的位置 
 } 
