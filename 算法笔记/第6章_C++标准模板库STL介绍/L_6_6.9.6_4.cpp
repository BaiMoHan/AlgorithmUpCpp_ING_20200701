//sort()�ĵ��������������Ĭ�ϰ��մ�С�����˳������
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int a[]={2,5,89,55,67};
	for(int i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");
	sort(a,a+5);//����compare�����Ļ�����Ĭ�ϴ�С��������
	for(int i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
} 
