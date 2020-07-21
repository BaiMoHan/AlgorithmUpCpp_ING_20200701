//sort()对char型数组排序,按照字典序 
#include<stdio.h>
#include<algorithm>
using namespace std;
int main() 
{
	char c[]={'T','W','A','H'};
	for(int i=0;i<4;i++)
		printf("%c ",c[i]);
	printf("\n"); 
	sort(c,c+4);//注意是左闭右开区间 
	for(int i=0;i<4;i++)
		printf("%c ",c[i]);
}
