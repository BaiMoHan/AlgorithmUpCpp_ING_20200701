#include<stdio.h>
#define M 14
#define N 14 
int main()
{
	char a[M][N];//根据实际测试样例更改M,N 
	int i,j,sum=0,count,p,q,x,y,n,m;
	//读入测试样例的行列数
	scanf("%d %d",&m,&n);
	for(i=0;i<=n-1;i++)
	 scanf("%s",a[i]);//读入地图状况 
	
	for(i=0;i<=m-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			//首先判断是否可以放置炸弹
			if(a[i][j]=='.')
			{
				count=0;//开始计数
				x=i;
				y=j;	//坐标操作，临时变量存储 
				//下面按照上下左右的顺序来统计可击杀的敌人数 
				
				//向上统计 
				while(a[x][y]!='#')//当不是墙的时候就继续统计 
				{
					if(a[x][y]=='G')
					{
						count++;
					 } 
					 x--;//向上统计 
					 //要放在if外,因为有些地方可能既没有墙，也没有敌人 
				 } 
				 
				//向下统计,x,y已经改变要重新初始化
				x=i;
				y=j; 
				while(a[x][y]!='#')
				{
					if(a[x][y]=='G')
					{
						count++;
					}
					x++;//向下统计 
			    } 
			    
			    //向左统计，同样初始化x,y
				x=i;
				y=j;
				while(a[x][y]!='#')
				{
					if(a[x][y]=='G')
					{
						count++;
					}
					y--;//向左统计 
				 } 
				 
				 //向右统计，同样初始化x,y
				 x=i;
				 y=j;
				 while(a[x][y]!='#')
				 {
				 	if(a[x][y]=='G')
				 	{
				 		count++;
					 }
					 y++;//向右统计 
					 
				  } 
				  if(count>sum)//统计最大的杀敌数 
				  {
				  	sum=count;
				  	p=i;
				  	q=j;
				  	//同时要记录坐标 
				  }
			 } 
		}
	 } 
	 printf("将炸弹放置在（%d,%d）处，最多可消灭%d个敌人\n",p,q,sum);
	 return 0;
}
