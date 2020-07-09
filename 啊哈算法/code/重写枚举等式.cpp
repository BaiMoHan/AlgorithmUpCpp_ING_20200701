#include<stdio.h>
int a[10],book[100],total;
void deep_first_search(int step);
int main()
{
	deep_first_search(1);//先从第一个盒子开始
	
	printf("总共能组成%d种可满足的等式",total/2);
	return 0; 
}
void deep_first_search(int step)
{
	int x,y,z,i; 
	if(step==10)//代表前面9个盒子已经放置好
	{
		//判断能否组成等式 
		x=a[1]*100+a[2]*10+a[3];
		y=a[4]*100+a[5]*10+a[6];
		z=a[7]*100+a[8]*10+a[9];
		if(x+y==z)
		{
			total++;
			printf("%d+%d=%d\n",x,y,z);
		 } 
		 return ;//返回上一步调用该函数的地方 
	 } 
	 for(i=1;i<=9;i++)
	 {
	 	if(book[i]==0)//判断是否可以打出牌 
	 	{
	 		a[step]=i;//放入盒子中 
			book[i]=1;//放入盒子后要标记
			
			deep_first_search(step+1);//下一步操作与这一步相同 
			book[i]=0;// 将牌收回，开始下一次尝试 
		 }
	 }
	 return ; 
}
