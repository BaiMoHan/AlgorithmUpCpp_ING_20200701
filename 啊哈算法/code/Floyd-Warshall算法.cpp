#include<stdio.h>
int main()
{
	int e[11][11],k,i,j,n,m,a,b,c;
	int infinity=999999;
	//初始化存储二维数组,读入顶点数与边数 
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=infinity;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		e[a][b]=c;
	 } 
	 
	//Floyd-Warshall算法
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(e[i][k]<infinity&&e[k][j]<infinity&&e[i][j]>e[i][k]+e[k][j])
					e[i][j]=e[i][k]+e[k][j];
	
	//输出最短路径结果 
	for(i=1;i<=n;i++) 
	{
		for(j=1;j<=n;j++)
			printf("%10d ",e[i][j]);
		printf("\n");
	}
	return 0;
}
