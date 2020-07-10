//PAT_B1001_Callatz猜想 
#include<stdio.h>
int main()
{
	int n,step=0;
	scanf("%d",&n);
	while(n!=1)
	{
		if(n%2)
		//n为奇数时 
			n=(3*n+1)/2;
		else
		//n为偶数时 
			n/=2;
		step++;
		//无论是奇数还是偶数进入循环意味着都执行一步		
	}
	printf("%d",step);
	return 0; 
 } 
