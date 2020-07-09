#include<stdio.h>
int map[15][15],book[15][15],m,n,num=-1;
void DFS(int x,int y,int color);
int main()
{
	int i,j,sum=0;
	//读入初始信息
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&map[i][j]);
	//对每一个点进行dfs 
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(map[i][j]>0)
			{
				DFS(i,j,num);
				sum++;
				num--;
			}
		}
	}
	//打印宝岛情况
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%3d ",map[i][j]);//便于打印工整，设置3d宽度
		//注意换行
		printf("\n"); 
	 }  
	 printf("共有孤立小岛个数%d",sum) ; 
	return 0;
}
void DFS(int x,int y,int color)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	//按照右下左上的顺序
	map[x][y]=color;//着色 
	book[x][y]=1;//初始标记上 
	int k,tx,ty;
	for(k=0;k<4;k++)
	{
		tx=x+next[k][0];
		ty=y+next[k][1];
		//判断是否越界 
		if(tx<0||ty<0||tx>m-1||ty>n-1)
			continue;
		if(map[tx][ty]!=0&&book[tx][ty]==0)
		{
			book[tx][ty]=1;//标记上 
		 	DFS(tx,ty,num);//深度优先搜索，尝试下一个结点 
		}
	}
	return ; 
}
