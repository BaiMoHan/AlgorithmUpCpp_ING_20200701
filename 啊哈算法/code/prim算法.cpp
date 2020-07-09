#include<stdio.h>
int main()
{
	int n,m,i,j,k,min,u,v,w;
	int e[7][7],dis[7],book[7]={0};
	int inf=99999999;//用infinity的缩写存储一个认为的正无穷大
	int count=0,sum=0;//count用来记录生成树中顶点的个数，sum用来存储路径之和
	//读入顶点数与边数
	scanf("%d %d",&n,&m);
	//初始化存储图的二维数组
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;//自己到自己的权值为0
			else e[i][j]=inf;//初始化为正无穷
	//开始读入边
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		//此处为无向图，存储矩阵为对称阵
		e[u][v]=w;
		e[v][u]=w; 
	 } 
	 //初始化dis数组，这里初始时选1号顶点，此时的生成树 
	 for(i=1;i<=n;i++)
	 	dis[i]=e[1][i];
	
	//prim算法核心部分
	//把1号顶点加入生成树中
	book[1]=1;//这里用book数组标记一个顶点是否已经加入生成树中
	count++;//加入一个顶点后计数
	while(count<n)
	{
		min=inf;
		for(i=1;i<=n;i++)//从dis中找出离当前生成树最小权值的边 
		{
			if(0==book[i] && dis[i]<min)  
			{
				min=dis[i];
				j=i;
			}
		}
		book[j]=1;//已用的顶点标记后不会再生成回路，因为构成回路的顶点之前一定已经加入到树中 
		count++;
		sum=sum+dis[j];
		//扫描当前顶点j所有的边，再以j为中间点，更新生成树到每一个非树顶点的距离
		for(k=1;k<=n;k++)
		{
			if(0==book[k] && dis[k]>e[j][k])
			//新加入的顶点构成了树，之前的顶点权值已经更新过，此时只要看新顶点能否带来权值上的改变 
				dis[k]=e[j][k];
		 } 
	 } 
	 printf("最小生成树的权值为%d",sum);
	 return 0;
}
