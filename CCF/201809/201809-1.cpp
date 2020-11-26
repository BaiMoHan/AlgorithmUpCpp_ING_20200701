#include<iostream>
#define N 1002
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
using namespace std; 
int num[N];
int re[N];
int main()
{
	#ifndef OJ
	freopen("201809-1.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	_rep(i,1,n)
		cin>>num[i];
	_rep(i,2,n-1)
	{
		re[i]=(num[i-1]+num[i]+num[i+1])/3;
	}
	re[1]=(num[1]+num[2])/2;
	re[n]=(num[n-1]+num[n])/2;
	_rep(i,1,n)
		cout<<re[i]<<" ";
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
