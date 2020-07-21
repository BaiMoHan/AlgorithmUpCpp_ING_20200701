//sort()的第三个参数不填，则默认按照从小到大的顺序排列
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int a[]={2,5,89,55,67};
	for(int i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");
	sort(a,a+5);//不加compare参数的话就是默认从小到大排列
	for(int i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
} 
