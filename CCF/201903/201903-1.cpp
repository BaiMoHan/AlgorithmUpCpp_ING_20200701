#include<stdio.h>
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);a<=(c);a++)
#define N 100005
int x[N];
int main()
{
	#ifndef OJ
	freopen("201903-1.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	_rep(i,1,n)
		scanf("%d",&x[i]);
		
	int min,max;
		
	if(x[1]<x[n])
	{
		min=x[1];
		max=x[n];
	}else
	{
		min=x[n];
		max=x[1];
	}
	printf("%d ",max);
	int mid;
	float a,b;
	if(n%2==0)//Å¼Êý 
	{
		if((x[n/2]+x[n/2+1])%2)
		{	
			a=x[n/2];
			b=x[n/2+1];
			printf("%.1f ",(a+b)/2);
		}
		else
		{
			printf("%d ",(x[n/2]+x[n/2+1])/2); 
		}

	}else
	{
		printf("%d ",x[n/2+1]);
	}
	printf("%d",min);
	
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
