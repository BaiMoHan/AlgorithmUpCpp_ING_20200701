#include<stdio.h>
#define N 5
int main()
{
	int count[N+1];
	int i,j,temp;
	for(i=1;i<N+1;i++)
	{
		scanf("%d",&count[i]);
	}
	for(i=1;i<N;i++)//N个数字冒泡只需要N-1轮 
	{
		for(j=1;j<N+1-i;j++)
		{
			if(count[j]>count[j+1])
			{
				temp=count[j+1];
				count[j+1]=count[j];
				count[j]=temp; 
			}
		}
	}
	for(i=1;i<N+1;i++)
	{
		printf("%d ",count[i]);
	}
	return 0;
 } 
