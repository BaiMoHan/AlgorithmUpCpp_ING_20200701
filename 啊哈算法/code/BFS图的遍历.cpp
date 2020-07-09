#include<stdio.h>
int main()
{
	int i,j,n,m,a,b,cur,book[101]={0},e[101][101];
	int que[10001],head,tail;
	//读入顶点数与边数 
	scanf("%d %d",&n,&m);
	//初始化二维矩阵
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j)	e[i][j]=0;//自身到自身的为0
			else e[i][j]=9999999;//这里假设9999999为正无穷
	
	//读入顶点之间的边
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		e[a][b]=1;
		e[b][a]=1;//无向图的对称性 
	 } 
	 //初始化队列 
	 head=1;
	 tail=1;
	 //从1号顶点出发，开始入队
	 que[tail]=1;
	 tail++;
	 book[1]=1;//标记1号顶点已经访问
	 
	 //广度优先搜索，当队列不为空时循环执行
	 while(head<tail)
	 {
	 	cur=que[head];//当前正在访问的顶点编号
		for(i=1;i<=n;i++)//从1~n个结点依次尝试
		{
			//判断顶点cur到顶点i是否有边，并判断顶点i是否已经访问过
			if(e[cur][i]==1&&book[i]==0)
			{
				//说明顶点cur到顶点i有边，且没有被访问过，入队
				que[tail]=i;
				tail++;//入队 
				book[i]=1; //标记已经访问 
			 } 
		 } 
		 //如果tail大于n，则说明所有顶点 
	 	if(tail>n)
	 	{
	 		break;
		 }
	 	head++;//每次搜索完之后，要出队以拓展完的结点，才能进行下一次拓展 
	 }
	 //打印广度优先搜索顺序
	 for(i=1;i<tail;i++)
	 	printf("%d ",que[i]);
	 	
	return 0;
}
