#include<stdio.h>
struct note
{
	int x;//放横坐标 
	int y;//放纵坐标 
	int f;//放置父亲在队列中的编号，以便打印路径
	int s;//存放步数 
 }que[2501],stack[10];//考虑到地图最多为50X50,拓展不会超过2500
 int main() 
 {
 	int map[51][51]={0},book[51][51]={0};
 	//map数组用来存放地图状况，book数组用来标记已经走过的点
	int i,j,k,n,m,p,q,startx,starty,tx,ty,head,tail,flag;
	int next[4][2]={{0,1},{1,0},{0,-1},{0,-1}};
	//对应右下左上的坐标改变顺序
	//读入地图状况
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	 for(j=1;j<=m;j++)
	  scanf("%d",&map[i][j]);
	//读入初始位置与目标位置 
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	//队列初始化
	head=1;tail=1;
	que[tail].x=startx;
	que[tail].y=starty;
	que[tail].s=0;
	que[tail].f=0;
	tail++; 
	book[startx][starty]=1;//初始位置要标记，避免重复拓展
	flag=0;//用来标记是否达到目的地，1为已达到
	while(head<tail)//队列不为空的时候循环 
	{
		//枚举四个方向
		for(k=0;k<=3;k++)
		{
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			//判断是否越界
			if(tx<1||tx>n||ty<1||ty>n)
			 continue;
			//判断是否是障碍物或者已经在路径中
			
			if(map[tx][ty]==0&&book[tx][ty]==0)
			{
				//将已经到达的结点进行标记
				book[tx][ty]=1;
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].f=head;
				//该结点是从head拓展出来的，所以标记其父亲为head，方便求路径 
				que[tail].s=que[head].s+1;//步数是父亲的步数+1
				tail++;
				//上面为拓展的结点的入队操作 				 
			 } 
			 //判断是否已经达到目的地
			 if(tx==p&&ty==q)
			 {
			 	flag=1;
			 	break;
			  } 
		}
		if(flag==1)
		 break;//说明已经找到，跳出外层while循环
		head++;//一个拓展点找到后，其父亲出队后才能进行下一次拓展 
	 }	
	 //上面为全部搜索过程，下面打印搜索的结果
	 i=que[tail-1].s;//tail指向的是队尾的后一个位置,最后一个位置是tail-1
	 int top=0;//打印路径用栈 
	 j=tail-1;//从目的结点开始入栈 
	 for(k=0;k<=i;k++)
	 {
	 	stack[top++]=que[j];
	 	j=que[j].f;//每次指向其父亲 
	 }
	 //打印路径
	 while(top>=0)
	 {
	 	printf("目的地的路径为:\n");
		printf("（%d,%d）——>\n",stack[top].x,stack[top].y); 
		printf("总共需要%d步",que[tail-1].s);
		top--; 
	  } 
	  return 0;
 }
