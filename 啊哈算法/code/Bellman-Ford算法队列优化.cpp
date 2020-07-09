#include<stdio.h>
int main()
{
	int n,m,i,j,k;
	//u,v,w的数组大小要根据实际情况来设置，要比边数m的最大值大1
	int u[8],v[8],w[8];
	
	//first要比n的最大值大1，next要比m的最大值大1
	int first[6],next[8];
	
	int dis[6]={0},book[6]={0};
	//book数组用来标记那些顶点已经在队列中，此处声明时已经初始化 
	
	int que[101]={0},head=1,tail=1;//定义一个队列，并初始化队列
	int inf=99999999;//此处代表无穷大
	
	//读入边数和顶点数
	scanf("%d %d",&n,&m);
	//初始化dis数组，为1号顶点到其他顶点的初始距离
	
	for(i=2;i<=n;i++)
	//声明时候已经初始化dis数组为0,1号顶点到自身为0,因此从2号顶点开始初始化 
		dis[i]=inf;
		
	//初始化first数组，-1表示1~n顶点都暂时没有边
	for(i=1;i<=n;i++)
		first[i]=-1;
	//读入边的信息，构建邻接表
	for(i=1;i<=m;i++)
	{
		//从顶点u[i]到顶点v[i]的权值为w[i] 
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		next[i]=first[u[i]];
		first[u[i]]=i;
	 } 
	 
	 //1号顶点入队
	 que[tail]=1;
	 tail++;
	 book[1]=1;//标记1号顶点已经入队
	 while(head<tail)//队列不为空时循环
	{
		k=first[que[head]];//当前需要处理的队首顶点
		while(k!=-1)//遍历当前顶点的所有边
		{
			//判断是否松弛
			if(dis[v[k]]>dis[u[k]]+w[k])
			{
				dis[v[k]]=dis[u[k]]+w[k];
				//下面考虑该顶点是否已经在队列中
				if(0==book[v[k]])
				{
					que[tail]=v[k];
					tail++;//入队操作 
					book[v[k]]=1; //入队之后标记 
				 }
			 }
			 k=next[k];
		 } 
		 //出队 
		 book[que[head]]=0;
		 head++;
	}
	//打印最短路径
	for(i=1;i<=n;i++)
		printf("%d ",dis[i]);
	
	return 0; 
	
}
