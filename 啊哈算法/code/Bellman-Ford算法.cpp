#include<stdio.h>
int main()
{
	int dis[10],i,k,n,m,u[10],v[10],w[10];
	int inf=99999999;//此处代表正无穷
	//读入顶点数与边数
	scanf("%d %d",&n,&m);
	
	//读入边,顶点u[i]到v[i]的权值为w[i] 
	for(i=1;i<=m;i++)
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		
	//初始化dis数组，这里是1号顶点到其余各个顶点的初始路程
	for(i=1;i<=n;i++)
		dis[i]=inf;
	dis[1]=0;//1号顶点到自身为0
	
	//Bellman-Ford算法核心语句 
	for(k=1;k<n;k++)//此处循环n-1轮，因为n个顶点之间最多n-1条边
		for(i=1;i<=m;i++)
			if(dis[v[i]]>dis[u[i]]+w[i])
				dis[v[i]]=dis[u[i]]+w[i];
	 //输出最终的结果
	  for(i=1;i<=n;i++)
	  	printf("%d ",dis[i]);
	
	return 0;
}
