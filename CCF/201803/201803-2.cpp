#include<iostream>
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define N 103
int ball[N][2];//ball[i][0]为坐标,ball[i][1]为移动速度矢量 
//#define OJ 98
using namespace std;
int main()
{
	#ifndef OJ
	freopen("201803-2.txt","r",stdin);
	#endif
	int n,l,t;
	cin>>n>>l>>t;
	_rep(i,0,n)
	{
		cin>>ball[i][0];
		ball[i][1]=1;//规定向右移动为正 
	}
	_rep(i,0,t)
	{
		_rep(j,0,n)	//每个球先移动一次
		{
			ball[j][0]+=ball[j][1];
			if(ball[j][0]==0||ball[j][0]==l)	//端点处
			{
				ball[j][1]=0-ball[j][1];
			 } 
		 } 
		 
		//检查碰撞,修改移动速度
		_rep(k,0,n)
			_rep(z,k+1,n)
				if(ball[k][0]==ball[z][0])
				{
					ball[k][1]=0-ball[k][1];
					ball[z][1]=0-ball[z][1];
				 } 
	}
	
	_rep(i,0,n)
	{
		cout<<ball[i][0]<<" ";
	}
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
