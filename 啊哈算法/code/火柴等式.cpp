#include<stdio.h>
int count(int x);//统计组成的数字要用的火柴根数 
int main()
{
	int i,j,k,sum=0,n;//sum用来计数等式成立的个数
	scanf("%d",&n);//输入给定的火柴数
	
	//开始枚举
	for(i=0;i<=1111;i++)
	{
		for(j=0;j<=1111;j++)
		{
			k=i+j;//通过计算出k而不是继续for可减少复杂度
			
			//下面通过 count函数判断是否能拼成等式
			if(count(i)+count(j)+count(k)==n-4)//除去符号占用的火柴数
			{
				printf("%d+%d=%d\n",i,j,k);
				sum++;
			 } 
		}
	 } 
	 printf("可满足的等式一共有%d种\n",sum);
	 return 0;
}
int count(int x)
{
	int sum=0;//用来计数拼成x需要多少根火柴
	int data[10]={6,2,5,5,4,5,6,3,7,6};
	//该数组存放对应下标数字所需要的火柴 
	while(x/10!=0)//依次取位
	{
		sum+=data[x%10];//依次取末尾求火柴根数
		x=x/10; 
	 } 
	 sum+=data[x];//退出循环后是只有一位数，还需要统计火柴根数
	 return sum;//返回该数字所需要的火柴数 
 } 
