#include<stdio.h>
int n,m,e[9][9],root,num[9],low[9],index;
int min(int x,int y);//找出x和y中最小的那个数
void dfs(int cur,int father);//找出割边的函数
int main()
{
	int i,j,x,y;
	//读入顶点与边数
	scanf("%d %d",&n,&m);
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
	 dfs(1,root);
	 return 0;
 } 
int min(int a,int b)
{
	return a<b?a:b;
}
void dfs(int cur,int father)
{
	int i,j;
	index++;
	num[cur]=index;
	low[cur]=index;
	for(i=1;i<=n;i++)
	{
		if(1==e[cur][i])
		{
			if(0==num[i])
			{
				dfs(i,cur);
				low[cur]=min(low[i],low[cur]);
				if(low[i]>num[cur])
					printf("%d-%d为割边\n",cur,i);
			}
			else if(i!=father)
			{
				low[cur]=min(low[cur],num[i]);
			}
		}
	 } 
 } 








