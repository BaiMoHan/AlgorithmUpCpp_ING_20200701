
#include<iostream>
using namespace std;
 
bool chess[6][6]={false};//利用的只有中心的4x4
bool flag;
int step;
int r[]={-1,1,0,0,0};//便于翻棋操作,按照上下左右的规则 
int c[]={0,0,-1,1,0};
 
bool judge_all(void)//判断“清一色”
{
	int i,j;
	for(i=1;i<5;i++)
		for(j=1;j<5;j++)
			if(chess[i][j]!=chess[1][1])
				return false;
	return true;
}
 
void flip(int row,int col)//翻棋
{
	int i;
	for(i=0;i<5;i++)
		chess[row+r[i]][col+c[i]]=!chess[row+r[i]][col+c[i]];
	return;
}
 
void dfs(int row,int col,int deep) //深搜的迭代回溯是重点，很容易混乱
{
	if(deep==step)
	{
		flag=judge_all();
		return;
	}
 
	if(flag||row==5)return;
 
	flip(row,col);       //翻棋
	if(col<4)
		dfs(row,col+1,deep+1);
	else
		dfs(row+1,1,deep+1);
 
	flip(row,col);      //不符合则翻回来
	if(col<4)
		dfs(row,col+1,deep);
	else
		dfs(row+1,1,deep);
 
	return;
}
 
int main(void)
{
	char temp;
	int i,j;
	for(i=1;i<5;i++)
		for(j=1;j<5;j++)
		{
			cin>>temp;
		    if(temp=='b') 
			    chess[i][j]=true;
		}
 
    for(step=0;step<=16;step++)  //对每一步产生的可能性进行枚举
	{                            //至于为什么是16，考虑到4x4=16格，而每一格只有黑白两种情况，则全部的可能性为2^16
		dfs(1,1,0);
		if(flag)break;
	}
 
	if(flag)
		cout<<step<<endl;
	else
		cout<<"Impossible"<<endl;
	return 0;
}

