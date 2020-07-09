#include<stdio.h>
int book[101],sum,n,e[101][101];
void dfs(int cur);//cur是当前顶点所在编号
int main()
{
	int i,j,m,a,b;
	//此例中为无向图 
	scanf("%d %d",&n,&m);//读入顶点数和边数 
	for(i=1;i<=n;i++)//使用邻接矩阵来存储,注意此处e[0][0]的横纵是没有用来存储的 
		for(j=1;j<=n;j++)
		{
			if(i==j)
				e[i][j]=0;//自身到自身无路
			else
				e[j][j]=9999999;//此处假设999999为无穷大 
		}
	//读入顶点之间的联通关系
	for(i=0;i<m;i++)//已知边数，这里读入的是边的关系 
	{
		scanf("%d %d",&a,&b);
		e[a][b]=1;//有边无权重就设置为1
		e[b][a]=1;//无向图是双方都有边 
	 } 
	 //首先从1号顶点出发
	 book[1]=1;//标记1号顶点已经访问 
	 dfs(1);//从1号顶点开始遍历
	 return 0; 
	
 } 
 void dfs(int cur)//cur是当前所在的顶点编号
 {
 	int i;
 	printf("%d ",cur);
 	sum++;//统计已经访问的结点数目
	if(sum==n)
		return ;//所有结点访问完直接退出
	for(i=1;i<=n;i++)//从1号顶点到n号顶点依次查找是否有边相连 
	{
		if(e[cur][i]==1&&book[i]==0)
		{
			book[i]=1;//已经访问过的结点要标记上
			dfs(i);//深度优先搜索，新访问到的结点继续往下遍历 
		}
	 } 
	 return ;
  } 
