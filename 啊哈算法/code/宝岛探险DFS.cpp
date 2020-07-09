#include<stdio.h>
int map[15][15],book[15][15],m,n,sum=1;
void DFS(int x,int y);
int main()
{
	int i,j,startx,starty;
	//读入初始信息
	scanf("%d %d %d %d",&m,&n,&startx,&starty);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&map[i][j]);
	book[startx][starty]=1;//初始位置标记为1
	DFS(startx,starty);
	printf("岛屿的面积为%d\n",sum);
	return 0;
}
void DFS(int x,int y)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	//按照右下左上的顺序
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
			sum++;//统计陆地面积 
		 	DFS(tx,ty);//深度优先搜索，尝试下一个结点 
		}
	}
	return ; 
}
