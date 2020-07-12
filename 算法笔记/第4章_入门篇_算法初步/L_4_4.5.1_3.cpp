//找到递增序列中第一个大于x的数的位置，二分查找法
int upper_bound(int a[],int left,int right,int x)
{
	int mid;		//取区间中点
	while(left<right)	//当left==right即为所求位置
	{
		mid=left+(right-left)/2;	//取中点，防御性编程
		if(a[mid]>right)	//找第一个大于的，与上例相比此处不需要加等号 
			right=mid;		//此例不需要mid+1，因为是找第一个
		else 
			left=mid+1;		//在[mid,right]区间中找 
	 } 
	 return left;			//返回夹出来的位置 
 } 
