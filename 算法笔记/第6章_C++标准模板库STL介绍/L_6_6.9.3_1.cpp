//reverse(it,it2)
//������ָ����[it,it2)֮���Ԫ�ػ��������ĵ�������[it,it2)��Χ�ڵ�Ԫ�ؽ��з�ת
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[10]={10,11,12,13,14,15};
	for(int i=0;i<6;i++)
		printf("%d ",a[i]); 
	printf("\n\n");
	reverse(a,a+4);//��a[0]~a[3]��ת,ע�ⷴת����������ҿ� 
	for(int i=0;i<6;i++)
		printf("%d ",a[i]); 
	return 0;
 } 
