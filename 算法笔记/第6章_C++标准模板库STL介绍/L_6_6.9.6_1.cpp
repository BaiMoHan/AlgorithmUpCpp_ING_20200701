//sort(��Ԫ�ص�ַ(����),βԪ�صġ���һ������ַ(����),�ȽϺ���(�Ǳ���))
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[6]={9,100,25,6,2,0};
	for(int i=0;i<6;i++)
		printf("%d ",a[i]);
	printf("\n\n");
	sort(a,a+4);//��a[0]~a[3]��С��������
	for(int i=0;i<6;i++)
		printf("%d ",a[i]);
	printf("\n\n");
	sort(a,a+6);//���������С�������� 
	for(int i=0;i<6;i++)
		printf("%d ",a[i]);
	return 0; 
 } 
