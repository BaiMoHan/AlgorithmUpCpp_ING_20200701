#include<stdio.h>
struct node{
	int x;//顶点编号
	int s;//转机次数 
};
int main()
{
	struct node que[2501];
	int e[51][51]={0},book[51]={0};
	int head,tail;
	int i,j,m,n,a,b,cur,start,end,flag=0;
	//读入顶点数，边数，起点，终点 
	scanf("%d %d %d %d",&n,&m,&start,&end);
	//初始化二维矩阵
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=99999999;
			
	//读入城市航线信息
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		e[a][b]=1;
		e[b][a]=1;//此处为无向图 
	 } 
	 head=1;
	 tail=1;
	 que[tail].x=start;
	 que[tail].s=0;
	 tail++;//队列初始化
	 book[start]=1;//标记start号城市
	 
	 //当队列不为空的时候执行循环
	 while(head<tail)
	 {
	 	cur=que[head].x;//当前队列中首城市的编号
		for(j=1;j<=n;j++)//从1~n顶点中依次广度优先搜索那些城市可以从当前城市到达 
		{
			if(e[cur][j]!=99999999&&book[j]==0)
			{
				//如果从城市cur到城市j有航班并且判断j是否已经在队列中
				que[tail].x=j;
				que[tail].s=que[head].s+1;//转机次数为其父结点+1
				tail++;//完成将城市j入队的操作
				book[j]=1;//入队之后要标记 
			}
			//如果到达目标城市则停止拓展
			if(que[tail-1].x==end)
			{
				flag=1;//flag用于跳出外层while循环，因为该判断条件只能跳出内层 
				break;//跳出for循环 
			 } 
		 } 
		 if(flag==1)
		 	break;//找到目的城市，跳出拓展
		head++;//一个点拓展结束后，要将其父节点出队 
	  } 
	  printf("最少的转机次数为%d",que[tail-1].s);
	  return 0;
}
