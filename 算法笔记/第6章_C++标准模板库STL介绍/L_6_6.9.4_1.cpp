//next_permutation()����һ��������ȫ�����е���һ������
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[10]={1,2,3,4,5,6};
	//a[0]~a[2]֮���������Ҫ���next_permutation
	do{
		printf("%d%d%d\n",a[0],a[1],a[2]);
	} while(next_permutation(a,a+6));//next_permutation���Ѿ��ﵽȫ���е����һ��ʱ�᷵��false 
	return 0;
 } 
