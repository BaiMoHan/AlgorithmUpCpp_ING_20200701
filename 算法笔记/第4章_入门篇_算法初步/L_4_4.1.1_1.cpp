//选择排序,从小到大 
void selectsort()
{
	for(int i=1;i<=n;k++)
	{
		//进行n趟操作 
		int k=i;
		for(int j=1;j<=n;j++)
		{
			//在未排序的区间中选出最小的元素，下标为k
			if(a[i]<a[k])
				k=j; 
		 } 
		 //每一轮找到最小的元素后交换
		 int temp;//其他教材会把i!=k作为交换条件，实际上交换语句耗时不多 
		 temp=a[i];
		 a[i]=a[k];
		 a[k]=temp; 
	}
 } 
