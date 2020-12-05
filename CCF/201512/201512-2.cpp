#include<iostream>
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
using namespace std;
#define N 33
#define OJ 98
int mp[N][N];
int res[N][N];
int main()
{
	#ifndef OJ
	freopen("201512-2.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	_rep(i,0,n)
	{
		_rep(j,0,m)
		{
			cin>>mp[i][j];
			res[i][j]=mp[i][j];
			//读取的时候判断横向的
			if(j>=2)
			{
				if(mp[i][j-2]==mp[i][j-1]&&mp[i][j-1]==mp[i][j])
				{
					res[i][j-2]=0;
					res[i][j-1]=0;
					res[i][j]=0;
				}
			 } 
		}
	 }
	//判断纵向的 
	_rep(i,0,m)
	{
		_rep(j,0,n)
		{
			if(j>=2)
			{
				if(mp[j-2][i]==mp[j-1][i]&&mp[j-1][i]==mp[j][i])
				{
					res[j-2][i]=0;
					res[j-1][i]=0;
					res[j][i]=0;
				}
			 } 
		}
	 } 
	 
	//输出结构 
	_rep(i,0,n)
	{
		_rep(j,0,m)
		{
			if(j!=m-1)
				cout<<res[i][j]<<" ";
			else
				cout<<res[i][j]<<endl;
		}
	 }
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
