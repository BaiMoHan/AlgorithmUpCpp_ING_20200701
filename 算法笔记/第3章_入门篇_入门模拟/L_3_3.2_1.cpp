//codeup_1934_找X 
#include<cstdio>
const int maxn=201;
int a[201];
int main()
{
	int n;
	//读取要输入的n个数 
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		//将输入的数存放到数组中
		scanf("%d",&a[i]); 
	}
	//查找数组索引
	int x;
	//读取需要查找的数 
	scanf("%d",&x); 
	for(int i=0;i<n;i++)
	{
		if(x==a[i])
		{
			printf("%d",i);
			return 0;//找到索引输出后直接退出 
		}
	 } 
	 printf("-1");
	 return 0; 
}
