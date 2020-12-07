#include<iostream>
#include<cmath>
#define N 2004
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
struct Node{
	int s;//开始时间
	int t;//结束时间 
}p1[N],p2[N];
using namespace std;
int main()
{
	#ifndef OJ
	freopen("201809-2.txt","r",stdin);
	#endif
	int n;	//工作时段
	cin>>n;
	//读取工作时间段 
	_rep(i,0,n)
	{
		cin>>p1[i].s>>p1[i].t;
	 } 
	_rep(i,0,n)
	{
		cin>>p2[i].s>>p2[i].t;
	 } 
	int i=0,j=0;
	long long res=0;
	int ts=0,tt=0;
	if((min(p1[i].t,p2[i].t)-max(p1[i].s,p2[i].s))>0)
	{
		res+=(min(p1[i].t,p2[i].t)-max(p1[i].s,p2[i].s));
	}
	ts=max(p1[i].s,p2[i].s);
	tt=max(p1[i].t,p2[i].t);
	i++;j++;
	while(i!=n&&j!=n)
	{
		if(p1[i].s<p2[j].s)
		{
			//考虑p1的区间相交
			if((min(p1[i].t,tt)-max(p1[i].s,ts))>0)
			{
				res+=(min(p1[i].t,tt)-max(p1[i].s,ts));
			}
				
			ts=max(p1[i].s,ts);
			tt=max(p1[i].t,tt);
			i++;
		}else{
			//考虑p2的区间相交
			if((min(p2[j].t,tt)-max(p2[j].s,ts))>0)
			{
				res+=min(p2[j].t,tt)-max(p2[j].s,ts);
			}
				
			ts=max(p2[j].s,ts);
			tt=max(p2[j].t,tt); 
			j++;
		}	
	 }
	if(i==n)
	{
		//还要判断p2 
		while(p2[j].s<tt&&j!=n)
		{
			res+=min(p2[j].t,tt)-max(p2[j].s,ts);
			ts=max(p2[j].s,ts);
			tt=max(p2[j].t,tt);
			j++;
		}
	}
	if(j==n)
	{
		//还要判断p1
		while(p1[i].s<tt&&i!=n)
		{
			res+=min(p1[i].t,tt)-max(p1[i].s,ts);
			ts=max(p1[i].s,ts);
			tt=max(p1[i].t,tt);
			i++;
		} 
	 } 
	cout<<res; 
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
