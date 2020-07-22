//想要sort()按照从大到小排列,则需要加入第三个参数cmp
//处理char型数据 
#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(char a,char b)
{
	return a>b;//按照从大到小排列，注意与priority_queue的写法是相反的 
 } 
 int main(){
	char a[]={'A','a','I','P','o'};
	for(int i=0;i<5;i++)
		printf("%c ",a[i]);
	printf("\n");
	sort(a,a+5);//不加compare参数的话就是默认从小到大排列
	for(int i=0;i<5;i++)
		printf("%c ",a[i]);
	printf("\n");
	sort(a,a+5,cmp);//不加compare参数的话就是默认从小到大排列
	for(int i=0;i<5;i++)
		printf("%c ",a[i]);
	printf("\n");
	return 0;
} 
