#include<stdio.h>
int main()
{
	int dis[10],i,k,n,m,u[10],v[10],w[10],bak[10],check,flag=0;
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
	{
		//每次松弛过后立即备份到bak数组中，方面后面判断是否松弛 
		for(i=1;i<=n;i++)
			bak[i]=dis[i]; 
		for(i=1;i<=m;i++)
			if(dis[v[i]]>dis[u[i]]+w[i])
				dis[v[i]]=dis[u[i]]+w[i];
		//松弛完毕后检查dis数组是否有更新
		 check=0;
		 for(i=1;i<=n;i++)
		{
			if(bak[i]!=dis[i])//说明更新了数组 
			{
				check=1;
				break;
			}
		}
		if(check==0)
			break;//说明没有更新，继续松弛也是浪费时间，退出循环 
	}
	//检测负权回路,看看再一轮松弛后，dis数组是否改变
	for(i=1;i<=m;i++)
		if(dis[v[i]]>dis[u[i]]+w[i])
		{
			dis[v[i]]=dis[u[i]]+w[i];
			flag=1;
	}
	
	 //输出最终的结果
	 if(flag==1) 
	 	printf("该图中有负权回路");
	else
	  for(i=1;i<=n;i++)
	  	printf("%d ",dis[i]);
	
	return 0;
}
