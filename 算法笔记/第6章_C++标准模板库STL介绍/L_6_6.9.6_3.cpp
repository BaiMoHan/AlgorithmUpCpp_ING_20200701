//sort()��char����������,�����ֵ��� 
#include<stdio.h>
#include<algorithm>
using namespace std;
int main() 
{
	char c[]={'T','W','A','H'};
	for(int i=0;i<4;i++)
		printf("%c ",c[i]);
	printf("\n"); 
	sort(c,c+4);//ע��������ҿ����� 
	for(int i=0;i<4;i++)
		printf("%c ",c[i]);
}
