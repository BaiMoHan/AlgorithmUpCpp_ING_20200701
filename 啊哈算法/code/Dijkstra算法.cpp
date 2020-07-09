#include<stdio.h> 
int main()
{
	int e[10][10],dis[10],book[10],i,j,n,m,t1,t2,t3,u,v,min;
	int inf=99999999;//假设此为正无穷大
	//读入顶点数与边数
	scanf("%d %d",&n,&m);
	//初始化存储矩阵
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=inf; 
			
	//读入图的信息
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&t1,&t2,&t3);
		e[t1][t2]=t3;
	}
	
	//初始化dis数组，此处为顶点1到其余各顶点的初始路程
	for(i=1;i<=n;i++)
		dis[i]=e[1][i];
	
	//book数组初始化，用来标记已经确定的顶点与未确定路程的顶点
	for(i=1;i<=n;i++)
		book[i]=0;
	
	book[1]=1;//从1号顶点开始往后找，开始标记1号顶点
	//Dijsktra算法核心语句
	for(i=1;i<n;i++)//从剩下的n-1个顶点中依次确定最短路径,需寻找n-1次 
	{
		//每次都寻找到离1号最近的点 
		min=inf;
		for(j=1;j<=n;j++)
		{
			if(book[j]==0&&dis[j]<min)
			{
				min=dis[j];
				u=j;
			}
		 } 
		 book[u]=1;//找到离1号最近的点后标记上
		for(v=1;v<=n;v++)//最近的点会成为到1号顶点的中转点，所以要更新依次dis数组的值 
		{
			if(e[u][v]<inf)
			{
				if(dis[v]>dis[u]+e[u][v])
					dis[v]=dis[u]+e[u][v];
			}
		}
	 } 
	for(i=1;i<=n;i++)
		printf("%d ",dis[i]);
	return 0;			 		 
}
