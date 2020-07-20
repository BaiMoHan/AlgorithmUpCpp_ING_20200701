//reverse(it,it2)
//将数组指针在[it,it2)之间的元素或者容器的迭代器在[it,it2)范围内的元素进行反转
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[10]={10,11,12,13,14,15};
	for(int i=0;i<6;i++)
		printf("%d ",a[i]); 
	printf("\n\n");
	reverse(a,a+4);//将a[0]~a[3]反转,注意反转区间是左闭右开 
	for(int i=0;i<6;i++)
		printf("%d ",a[i]); 
	return 0;
 } 
