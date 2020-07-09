#include<stdio.h>
int n,m,p,q,min=9999999,a[51][51],book[51][51];
void deep_first_search(int x,int y,int step);
int main()
{
	int i,j,startx,starty;
	//读入地图状况
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
			
	//读入初始坐标与目的坐标 
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	book[startx][starty]=1;//初始位置已经在路径中了 
	deep_first_search(startx,starty,0);
	
	printf("最短需要%d步",min); 
	return 0;
	
 } 
void deep_first_search(int x,int y,int step)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	//按照依次右下坐上的顺序，每组中第一个变化的是x坐标，第二个是y坐标 
	
	int tx,ty,k;
	if(x==p&&y==q)
	{
		//说明已经搜索到小哈的位置，下面判断是否是最小步数
		if(step<min)
		{
			min=step;
		 } 
		 return ;//这里必须要返回 
	 } 
	 
	 //按照右下左上的顺序依次枚举 
	 for(k=0;k<4;k++)
	 {
	 	//计算下一个点的坐标
		 tx=x+next[k][0];
		 ty=y+next[k][1];
		 
		 //判断下一步是否越界
		 if(tx<1||tx>n||ty<1||ty>n)
		 	continue;
			 
		 //判断下一步是否为障碍物或者已经在路径中 
		 if(a[tx][ty]==0&&book[tx][ty]==0)
		 {
		 	book[tx][ty]=1;//标记上
			deep_first_search(tx,ty,step+1);//下一步也相同，递归调用 
			
			book[tx][ty]=0;//尝试之后要取消标记，开始下一次标记 
		  } 		  
	  } 
	  return ;
}
