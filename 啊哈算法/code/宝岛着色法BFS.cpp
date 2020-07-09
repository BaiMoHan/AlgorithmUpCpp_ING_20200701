#include<stdio.h>
struct node{
	int x;//存放横坐标 
	int y;//存放纵坐标 
}que[100];//设置广度优先搜索的队列
int BFS(int x,int y,int color);
int book[15][15],map[15][15],m,n;//设置全局变量 
int main() 
{
	int i,j,startx,starty;
	//读入地图信息及初始位置
	scanf("%d %d %d %d",&m,&n,&startx,&starty);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&map[i][j]); 
	i=BFS(startx,starty,-1);
	printf("降落的岛屿的面积为:%d\n",i);
	//打印宝岛情况
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%3d ",map[i][j]);//便于打印工整，设置3d宽度
		//注意换行
		printf("\n"); 
	 } 
	return 0;
}
int BFS(int x,int y,int color)
{
	int head=0,tail=0,k,tx,ty;
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	//按照右下左上的顺序 
	que[tail].x=x;
	que[tail].y=y;
	map[x][y]=color;//初始着色 
	tail++;//初始位置入队
	book[x][y]=1;//标记已经入队的结点 
	while(head<tail)//当队列不为空时，广度遍历
	{
		for(k=0;k<4;k++)
		{
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			//判断是否越界 
			if(tx<0||ty<0||tx>m-1||ty>n-1)
				continue;
			if(map[tx][ty]!=0&&book[tx][ty]==0)
			{
				book[tx][ty]=1;//标记已经遍历到的结点
				que[tail].x=tx;
				que[tail].y=ty;
				map[tx][ty]=color;//着色操作 
				tail++;//入队操作
			 } 
		}
		head++; 
	 }  
	return tail;//陆地数就是入队的数目 	
}
