//随机选择算法，基于快排思想
//randPartition函数为快排中的随机选择主元并交换函数
//randSelect从数组a中返回第K大的函数 
int randSelect(int a[],int left,int right,int K) 
{
	if(left==right)		return a[left];	//边界
	int p=randPartition(a,left,right);	//保存一次快排划分操作后主元的位置
	int M=p-left+1;		//此时a[p]为数组中的第M大
	if(K==M)		//K恰好等于M,说明找到第K大的数
		return a[p];	//此时a[p]就是第K大的数
	else if(K<M)	//K比M小，说明第K大的数在a[p]的左边
		return randSelect(a,left,p-1,K);	//对a[p]的左边调用随机选择算法
	else		//K>M的情况,说明第K大的数在a[p]的右边
		return randSelect(a,p+1,right,K-M);	//在右侧寻找K-M大的数,本质还是数组a的第K大的数 
}
//上述算法未考虑K不合法的情况 

