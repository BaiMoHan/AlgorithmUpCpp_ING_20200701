//想要sort()按照从大到小排列,则需要加入第三个参数cmp
//处理double型数据 
#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(double a,double b)
{
	return a>b;//按照从大到小排列，注意与priority_queue的写法是相反的 
 } 
 int main(){
	double a[]={2.66,5.88,-89.1,-55.25,67};
	for(int i=0;i<5;i++)
		printf("%f ",a[i]);
	printf("\n");
	sort(a,a+5);//不加compare参数的话就是默认从小到大排列
	for(int i=0;i<5;i++)
		printf("%f ",a[i]);
	printf("\n");
	sort(a,a+5,cmp);//不加compare参数的话就是默认从小到大排列
	for(int i=0;i<5;i++)
		printf("%f ",a[i]);
	printf("\n");
	return 0;
} 
