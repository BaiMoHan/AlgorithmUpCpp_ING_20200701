//直接插入排序 从小到大 
int a[maxn],n;//n为元素个数，数组下标为1-n
void insertsort()
{
	for(int i=2;i<=n;i++)//从n-1个数后面依次选择数往前面插入
	{
		int temp=a[i],j=i;//temp临时存放a[i]，j从i开始往前面枚举到第一个数 
		while(j>1 && temp<a[j-1])
		{
			//一直往前面枚举，遇到小的就交换
			A[j]=A[j-1];//后移一位 
			j--; 
		}
		//移完之后留下的位置就是a[i]
		a[j]=temp;//插入一开始a[i]的值 
	 } 
 } 
