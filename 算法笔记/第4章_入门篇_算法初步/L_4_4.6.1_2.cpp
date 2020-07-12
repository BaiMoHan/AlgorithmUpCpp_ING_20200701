//合并两递增序列
int merge(int a[],int b[],int c[],int n,int m) 
{
	//将a[n]与b[m]两个数组合并至c[]中
	while(i<n&j<m)
	{
		//每次将最小的数合并至c中 
		if(a[i]<b[j])
			c[index++]=a[i];
		else
			c[index++]=b[j];
	 } 
	 //当其中一个数组中所有元素用完后，剩下的另一个数组直接合并 
	 while(i<n)
	 	c[index++]=a[i++];
	 while(j<n)
	 	c[index++]=b[j++]; 
}
