//��Ҫsort()���մӴ�С����,����Ҫ�������������cmp
//����char������ 
#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(char a,char b)
{
	return a>b;//���մӴ�С���У�ע����priority_queue��д�����෴�� 
 } 
 int main(){
	char a[]={'A','a','I','P','o'};
	for(int i=0;i<5;i++)
		printf("%c ",a[i]);
	printf("\n");
	sort(a,a+5);//����compare�����Ļ�����Ĭ�ϴ�С��������
	for(int i=0;i<5;i++)
		printf("%c ",a[i]);
	printf("\n");
	sort(a,a+5,cmp);//����compare�����Ļ�����Ĭ�ϴ�С��������
	for(int i=0;i<5;i++)
		printf("%c ",a[i]);
	printf("\n");
	return 0;
} 
