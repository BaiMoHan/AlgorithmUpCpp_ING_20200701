//PAT_B1001_Callatz���� 
#include<stdio.h>
int main()
{
	int n,step=0;
	scanf("%d",&n);
	while(n!=1)
	{
		if(n%2)
		//nΪ����ʱ 
			n=(3*n+1)/2;
		else
		//nΪż��ʱ 
			n/=2;
		step++;
		//��������������ż������ѭ����ζ�Ŷ�ִ��һ��		
	}
	printf("%d",step);
	return 0; 
 } 
