//��Ҫsort()���մӴ�С����,����Ҫ�������������cmp
#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;//���մӴ�С���У�ע����priority_queue��д�����෴�� 
 } 
 int main(){
	int a[]={2,5,89,55,67};
	for(int i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");
	sort(a,a+5);//����compare�����Ļ�����Ĭ�ϴ�С��������
	for(int i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");
	sort(a,a+5,cmp);//����compare�����Ļ�����Ĭ�ϴ�С��������
	for(int i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
} 
