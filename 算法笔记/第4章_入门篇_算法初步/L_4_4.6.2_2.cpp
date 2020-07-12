//归并排序的非递归实现
void mergesort(int a[])
{
	//step为组内元素个数，step/2为左区间元素个数，注意等号可以不取
	int step,i,mid;	//step为步长，i为计数器，mid为每组的中点 
	for(step=2;step/2<=n;step*=2)
	{
		//每step个元素一组，组内前step/2和后step/2个元素进行合并
		for(i=1;i<=n;i+=step)	//对每一组 
		{
			mid=i+step/2-1;		//左区间元素个数为step/2
			if(mid+1<=n)	//右区间存在元素则合并
			//左区间为[i,mid],右区间为[mid+1,min(i+step-1,n)]
				merge(a,i,mid,mid+1,min(i+step-1,n)); 
		}
	 } 
}
