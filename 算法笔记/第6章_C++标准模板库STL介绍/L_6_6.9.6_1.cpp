//sort(首元素地址(必填),尾元素的【下一个】地址(必填),比较函数(非必填))
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[6]={9,100,25,6,2,0};
	for(int i=0;i<6;i++)
		printf("%d ",a[i]);
	printf("\n\n");
	sort(a,a+4);//将a[0]~a[3]从小到大排序
	for(int i=0;i<6;i++)
		printf("%d ",a[i]);
	printf("\n\n");
	sort(a,a+6);//整个数组从小到大排序 
	for(int i=0;i<6;i++)
		printf("%d ",a[i]);
	return 0; 
 } 
