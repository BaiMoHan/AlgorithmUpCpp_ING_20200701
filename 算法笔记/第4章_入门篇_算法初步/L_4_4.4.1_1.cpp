//PAT_B1020_月饼 
#include<stdio.h>
#include<algorithm>//调用sort函数 
//定义月饼的结构体存放相关信息
#define N 1000
using namespace std; 
struct Mooncake{
	double store;//仓库存储量
	double total;//销售总金额
	double price;//月饼单价 
}mooncake[N]; 
bool cmp(Mooncake a,Mooncake b) //sort函数的cmp参数 
{
	//按单价从高到低 
	return a.price>b.price;
}
int main()
{
	int n,i;//种类数，计数器 
	double sum=0,needs;//销售净额和需求量
	//读入种类数与需求量
	scanf("%d %lf",&n,&needs); 
	//读入月饼每种种类的库存量 
	for(i=0;i<n;i++)
	{
		scanf("%lf",&mooncake[i].store);
	 } 
	//读入月饼每种种类全部售完的金额
	for(i=0;i<n;i++)
	{
		scanf("%lf",&mooncake[i].total);
	 } 
	//计算出每种月饼的单价 
	for(i=0;i<n;i++)
	{
		mooncake[i].price=mooncake[i].total/mooncake[i].store;
	}
	//按单价从高到低排序
	sort(mooncake,mooncake+n,cmp);
	//开始用贪心策略计算最大销售金额，按价格从高到低
	for(i=0;i<n;i++)
	{
		//如果库存量满足需求量，则按照需求量乘以单价
		if(mooncake[i].store>=needs)
		{
			sum+=mooncake[i].price*needs;
			break;//不必再继续往下找 
		 } 
		 else
		 {
		 	sum+=mooncake[i].total;//全部售完库存量 
		 	needs-=mooncake[i].store;//剩余不够的去下一个月饼种类里面找 
		  } 
	 } 
	 printf("最大销售金额为%.2f\n",sum);
	 return 0; 
 } 
