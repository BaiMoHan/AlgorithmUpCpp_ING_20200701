#include<stdio.h>
int n,m,e[9][9],root;
int num[9],low[9],flag[9],index;//index用来进行时间戳的递增
int min(int a,int b);//求出a和b两个数中最小的一个
void dfs(int cur,int father);//求割点的算法，借助深度优先搜索
int main()
{
	int i,j,x,y;
	//读入顶点数和边数 
	scanf("%d %d",&n,&m);
	//初始化图的存储二维数组 
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			e[i][j]=0;
	
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		e[x][y]=1;
		e[y][x]=1;
	}
	root=1;
	dfs(1,root);//从1号顶点开始深度优先遍历
	for(i=1;i<=n;i++)
	{
		if(1==flag[i])
			printf("割点为%d号顶点",i);
	 } 
	 return 0;
 } 
 int min(int x,int y)
 {
 	return x < y ? x : y ;
 }
 void dfs(int cur,int father)
 //传入的两个参数分别为当前顶点编号和父顶点的编号 
 {
 	int child=0,i,j;//child用来记录在生成树中当前顶点cur的儿子个数
	index++;//时间戳加1
	num[cur]=index;//当前顶点cur的时间戳
	low[cur]=index;//当前顶点能访问到最早顶点的时间戳，最开始是访问自己
	for(i=1;i<=n;i++)//枚举与当前顶点cur有边相连的顶点i
	{
		if(1==e[cur][i])//判断两顶点间是否有边 
		{
			if(0==num[i])//如果顶点i的时间戳为0，则说明顶点i还没有被访问过
			{
				child++;
				dfs(i,cur);//继续向下深度优先搜索
				//更新当前顶点cur能访问到最早顶点的时间戳
				low[cur]=min(low[cur],low[i]);
				//如果当前顶点不是根结点并且满足low[i]>=num[cur],则当前顶点为割点
				if(cur!=root && low[i]>=num[cur])
					flag[cur]=1;
				//如果当前顶点是根结点，在生成树中根结点必须要有两个儿子，那么这个根结点才是割点
				if(cur==root && 2==child)
					flag[cur]=1; 
			 } 
			 else if(i!=father)
			 //否则如果顶点i曾经被访问过，并且这个顶点不是当前顶点cur的父亲，则需要更新当前结点cur能否访问到最早顶点的时间戳
			 {
			 	low[cur]=min(low[cur],num[i]);
			  } 
		}
	 } 
 }
