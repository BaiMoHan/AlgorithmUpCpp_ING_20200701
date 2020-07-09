#include<stdio.h>
int min=99999999,book[101],n,e[101][101];
//此处假设99999999为正无穷
void dfs(int cur,int dis);//cur为当前结点的编号，dis为已经走过的路程
int main()
{
	int i,j,m,a,b,c;
	//读取顶点数和边数 
	scanf("%d %d",&n,&m);
	
	//初始化二位矩阵
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;//自身到自身的距离为0
			else e[i][j]=99999999;
			
	//读入城市道路的连通与距离
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		e[a][b]=c;//还要更新二维矩阵里面的距离 
	 } 
	 book[1]=1;//标记出发点1号城市已经在路径中
	 dfs(1,0);//从1号城市开始搜索
	 printf("最短路径为%d",min);//打印最短距离 
	return 0;
 }
void dfs(int cur,int dis)
{
	int j;
	//如果当前走过的路程已经大于上一次的最短路了，就没必要继续搜素了
	if(dis>min)
		return ;
	if(cur==n)//判断是否到达了目标城市
	{
		if(dis<min)//更新最小值
		{
			min=dis;
		 } 
		 return ;
	 } 
	 
	//深度优先搜索主体，从1~n号城市开始尝试
	for(j=1;j<=n;j++)
	{
		if(e[cur][j]!=99999999&&book[j]==0)
		{
			//判断是否有路径且是否已经搜索过
			book[j]=1;//标记J已经在路径中
			dfs(j,dis+e[cur][j]);//从J城市出发继续往下搜素
			book[j]=0;//搜索完成后要取消标记，开始另外的路径搜索 
		 } 
	 } 
	 return ;
	 
 } 
