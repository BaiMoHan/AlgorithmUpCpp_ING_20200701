#include<stdio.h>
int book[50][50],max,sum,end,m,n; 
char map[50][50];
struct node{
	int x;//横坐标 
	int y;//纵坐标 
	int f;//其父亲 
	int s;//步数 
}que[50],stack[20]; 
void breadth_first_search(int x,int y);//宽度优先搜索 
int count(int x,int y);//统计炸弹人函数
int main()
{
	int i,j,startx,starty,top=0;
	//读入地图信息
	scanf("%d %d %d %d",&m,&n,&startx,&starty);
	for(i=0;i<m;i++)
		{
		scanf("%s",map[i]);
	}

	max=count(startx,starty);
	breadth_first_search(startx,starty); 
	printf("最大杀敌数为%d个\n",max);
	printf("应该将炸弹人放在(%d,%d)处\n",que[end].x,que[end].y); 
	//开始打印路径
	while(end!=-1)
	{
		stack[top++]=que[end];//入栈
		end=que[end].f; 
	 } 
	 printf("放置路径为；\n"); 
	 while(top>=0)//出栈打印
	 {
	 	printf("（%d,%d）->\n",stack[top].x,stack[top].y);
	 	top--;
	  } 
	 
	return 0;
 } 
 void breadth_first_search(int x,int y)
 {
 	int head=0,tail=0,k,tx,ty;
 	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
 	que[0].x=x;
 	que[0].y=y;
 	que[0].f=-1;
 	que[0].s=0; 
 	tail++;//初始位置入队
	book[x][y]=1; //标记初始位置 
	while(head<tail)
	{
		//对父亲可达地方四个方向遍历 
		for(k=0;k<=3;k++)
		{
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			
			//判断是否越界
			if(tx<0||ty<0||tx>m-1||ty>n-1)
				continue;
			//判断路径是否可达
			if(map[tx][ty]=='.'&&book[tx][ty]==0)
			{
				book[tx][ty]=1;//标记已经达到的结点
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].f=head;//指向父亲，后面回溯 
				que[tail].s=que[head].s+1;
				tail++;//入队操作
				sum=count(tx,ty);//更新杀敌数 
				if(sum>max)
				{
					max=sum;
					end=tail;//存储目最大杀敌数位置 
				}
			 } 
		}
			 head++;//每次四个方向遍历完后，父亲出队，进行下一次拓展 
	}
		return ; 
	}

int count(int x,int y)
{
	int k=0,tx,ty;
	//下面按照右下左上的顺序依次统计杀敌数
	//每次统计前，都要重置坐标
	tx=x;
	ty=y;
	while(map[tx][ty]!='#')
	{
		if(map[tx][ty]=='G')
			k++;
		ty++;
	 } 
	 
	 tx=x;
	 ty=y;
	 while(map[tx][ty]!='#')
	 {
	 	if(map[tx][ty]=='G')
	 		k++;
	 	tx++;
	 }
	 
	 tx=x;
	 ty=y;
	 while(map[tx][ty]!='#')
	 {
	 	if(map[tx][ty]=='G')
	 		k++;
	 	ty--;
	 }
	 
	 tx=x;
	 ty=y;
	 while(map[tx][ty]!='#')
	 {
	 	if(map[tx][ty]=='G')
	 		k++;
	 	tx--;
	 }
	 
	 return k;
}
