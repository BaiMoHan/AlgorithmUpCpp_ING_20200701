#include<iostream>
#include<cmath>
#define N 2004
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
struct Node{
	int s;//��ʼʱ��
	int t;//����ʱ�� 
}p1[N],p2[N];
using namespace std;
int main()
{
	#ifndef OJ
	freopen("201809-2.txt","r",stdin);
	#endif
	int n;	//����ʱ��
	cin>>n;
	//��ȡ����ʱ��� 
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
			//����p1�������ཻ
			if((min(p1[i].t,tt)-max(p1[i].s,ts))>0)
			{
				res+=(min(p1[i].t,tt)-max(p1[i].s,ts));
			}
				
			ts=max(p1[i].s,ts);
			tt=max(p1[i].t,tt);
			i++;
		}else{
			//����p2�������ཻ
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
		//��Ҫ�ж�p2 
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
		//��Ҫ�ж�p1
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
