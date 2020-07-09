#include<stdio.h>
int max,sum,p,q,m,n,book[50][50];
char map[50][50];
void deep_first_search(int x,int y);
int count(int x,int y);
int main()
{
	int i,j,startx,starty;
	//读入地图信息以及初始位置 
	scanf("%d %d %d %d",&m,&n,&startx,&starty);
	for(i=0;i<m;i++)
			scanf("%s",map[i]);
	book[startx][starty]=1;
	deep_first_search(startx,starty);
	printf("应该将炸弹放在(%d,%d)处\n",p,q);
	printf("可炸死%d个敌人",max);
	return 0; 
}
void deep_first_search(int x,int y)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	//按照右下左上的枚举顺序
	int k,tx,ty;
	//每次开始下一次搜索之前都要统计现有点的杀敌数 
	sum=count(x,y);
	if(sum>max)//判断杀敌数
	{
		p=x;
		q=y;//记录最大位置的坐标 
		max=sum;//更新最大值 
	 } 
	
	//开始按照右下左上的顺序搜索下一个结点
	for(k=0;k<=3;k++)
	{
		tx=x+next[k][0];
		ty=y+next[k][1];
		//判断新结点是否越界
		if(tx<0||ty<0||ty>m-1||ty>n-1)
			continue;
		//判断结点是否已经遍历过	
		if(map[tx][ty]=='.'&&book[tx][ty]==0)
		{
			book[tx][ty]=1;//标记上;
		 	deep_first_search(tx,ty);//继续深度优先搜索 
		}	
	}
	return ;
}
int count(int x,int y)
{
	int k=0,tx,ty;
	//下面依次按照右下左上的顺序统计杀敌数,每次统计要重置初始坐标
	tx=x;
	ty=y; 
	while(map[tx][ty]!='#')
	{
		if(map[tx][ty]=='G')
		{
			k++;
		}
		ty++;//向右统计,这个不能放if里面，因为可能下一个位置是空地 
	}
	
	tx=x;
	ty=y;
	while(map[tx][ty]!='#')
	{
		if(map[tx][ty]=='G')
		{
			k++;
		}
		tx++;//向下统计，这个不能放if里面，因为可能下一个位置是空地 
	 } 
	 
	 tx=x;
	 ty=y;
	 while(map[tx][ty]!='#')
	 {
	 	if(map[tx][ty]=='G')
	 	{
	 		k++;
		 }
		 ty--;//向左统计，这个不能放在if里面，因为下一个位置可能是空地 
	 }
	 
	 tx=x;
	 ty=y;
	 while(map[tx][ty]!='#')
	 {
	 	if(map[tx][ty]=='G')
	 	{
	 		k++;
		 }
		tx--;//向上统计，这个不能放在if里面，因为下一个位置可能是空地 
	 }
	 
	 return k;//最后为总杀敌数 
	} 

