#include<iostream>
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define N 1004
#include<vector>
#include<algorithm>
using namespace std; 
struct Node1{
	int x;
	int y;
	int count;
}node[N];
vector<int> book; 
int score0;
int score1;
int score2;
int score3;
int score4;

int main()
{
	#ifndef OJ
	freopen("201912-2.txt","r",stdin);
	#endif
	
	
	int n;	//点对数量
	cin>>n;
	_rep(i,0,n)	//读取 
	{
		cin>>node[i].x>>node[i].y;
		node[i].count=0;
	}
	//暴力找中心,统计上下左右是否有点 
	int tx=0,ty=0;
	_rep(i,0,n)
	{
		tx=node[i].x;
		ty=node[i].y;
		_rep(j,0,n)
		{
			if(i==j)
				continue;
			//上
			if(node[j].x==tx&&node[j].y==ty+1)
				node[i].count++;
			//下 
			if(node[j].x==tx&&node[j].y==ty-1)
				node[i].count++;
			//左 
			if(node[j].x==tx-1&&node[j].y==ty)
				node[i].count++;
			//右 
			if(node[j].x==tx+1&&node[j].y==ty)
				node[i].count++;
			if(node[i].count==4)	//找到回收站地址并记录 
			{
				book.push_back(i);
				break;
			}
		}
	 } 
	 
	 
	 //检查每个回收站的分数 
	 int score=0;
	_rep(i,0,book.size())
	{
		tx=node[book[i]].x;
		ty=node[book[i]].y;
		_rep(j,0,n)
		{
			if(j==book[i])	//扫描到自己
				continue; 
			//左上
			if(node[j].x==tx-1&&node[j].y==ty+1)
				score++;
			//右上
			if(node[j].x==tx+1&&node[j].y==ty+1)
				score++;
			//左下 
			if(node[j].x==tx-1&&node[j].y==ty-1)
				score++;
			//右下 
			if(node[j].x==tx+1&&node[j].y==ty-1)
				score++;
		 } 
		switch(score){
			case 0:score0++;break;
			case 1:score1++;break;
			case 2:score2++;break;
			case 3:score3++;break;
			case 4:score4++;break;
			default:cout<<score<<endl;break;
		}
		score=0;
	}
	cout<<score0<<endl;
	cout<<score1<<endl;
	cout<<score2<<endl;
	cout<<score3<<endl;
	cout<<score4<<endl;
	
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
