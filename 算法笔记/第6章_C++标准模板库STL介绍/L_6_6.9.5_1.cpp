//fill()可以把数组或容器中的某一段区间赋为某个相同的值
//注意西方编程设计的区间多数都是左闭右开 
//和memset不同，这里的赋值可以是数组类型对应范围中的任意值
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[5]={1,2,3,4,5};
	fill(a,a+5,233);//将a[0]~a[4]均赋值为233 
	for(int i=0;i<5;i++)
		printf("%d ",a[i]);
	return 0;
 } 
