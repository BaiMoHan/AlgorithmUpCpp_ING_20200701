//��Ҫsort()���մӴ�С����,����Ҫ�������������cmp
//����double������ 
#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(double a,double b)
{
	return a>b;//���մӴ�С���У�ע����priority_queue��д�����෴�� 
 } 
 int main(){
	double a[]={2.66,5.88,-89.1,-55.25,67};
	for(int i=0;i<5;i++)
		printf("%f ",a[i]);
	printf("\n");
	sort(a,a+5);//����compare�����Ļ�����Ĭ�ϴ�С��������
	for(int i=0;i<5;i++)
		printf("%f ",a[i]);
	printf("\n");
	sort(a,a+5,cmp);//����compare�����Ļ�����Ĭ�ϴ�С��������
	for(int i=0;i<5;i++)
		printf("%f ",a[i]);
	printf("\n");
	return 0;
} 
