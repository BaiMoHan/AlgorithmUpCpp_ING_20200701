#include<stdio.h>
int map[51][51],book[51][51],m,n,flag=0,top;
struct node{
	int x;//存放横坐标
	int y;//存放总坐标 
}line[50];//构建一个栈，方便打印路径 
void dfs(int x,int y,int front);
//深度优先搜索，xy表示当前处理的格子的坐标，front表示进水口的位置
int main()
{
	int i,j,num;
	//读入地图初始信息
	scanf("%d %d",&m,&n);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&map[i][j]);
	dfs(1,1,1);
	if(!flag)
	{
		printf("没有铺设方案!\n");
	}
	return 0;
 } 
void dfs(int x,int y,int front)
{
	int i; 
	//最后连通的时候，新的front一定是对准了出水口
	if(x==m&&y==n+1)
	{
		flag=1;//表示已经找到铺设方案 
		//打印路径
		for(i=1;i<=top;i++)
			printf("(%d,%d)->\n",line[i].x,line[i].y); 
		return ;
	 } 
	//判断是否越界
	if(x<1||x>m||y<1||y>n)
		return ;
	//判断管道是否已经被使用过
	if(book[x][y]==1)
		return ;
	//将当前尝试的左边入栈	
	top++;
	line[top].x=x;
	line[top].y=y; 
	book[x][y]=1;//标记当前的格子 
		
	//当前管道是弯管的情况
	if(map[x][y]<5)
	{
		//按照出水口左上右下的顺序选择管道的摆放策略
		if(front==1)//出水口在左边的情况
		{
			dfs(x+1,y,2);//3号这种摆放方式
			dfs(x-1,y,4);//4号这种摆放方式 
		}
		if(front==2)//出水口在上边的情况
		{
			dfs(x,y+1,1);//1号这种摆放方式
			dfs(x,y-1,3);//4号这种摆放方式 
		 } 
		if(front==3)//出水口在右边的情况
		{
			dfs(x-1,y-1,4);//1号这种摆放方式
			dfs(x+1,y-1,2);//2号这种摆放方式 
		 } 
		if(front==4)//出水口在下边的情况 
		{
			dfs(x,y+1,1);//2号这种摆放方式
			dfs(x,y-1,3);//3号这种摆放方式 
		 } 
	 } 
		
	//当前管道是直管的情况
	if(map[x][y]>4)
	{
		//按照出水口左上右下的顺序选择管道的摆放策略 
		if(front==1)//进水口在左边的情况
			dfs(x,y+1,1);//只能使用5号这种摆放方式 
		//进水口在上边的情况
		if(front==2)
			dfs(x+1,y,2);//只能使用6号这种摆放方式
		//进水口在右边的情况 
		if(front==3)
			dfs(x,y-1,3);//只能使用5号这种摆放方式
		//进水口在下边的情况 
		if(front==4)
			dfs(x-1,y,4);//只能使用6号这种摆放方式 
	}
	book[x][y]=0;//一次搜索完之后要取消标记才能开始下一次标记
	top--;//同时还要出栈 
	return ; 
}
