#include<iostream>
#define _rep(a,b,c) for(int (a)=b;(a)<=(c);a++) 
#define N 1003
#define OJ 98
long  re[N];	//��¼��i�������߹�
long num[N];	//��¼��i�������߹������Ŀ 
using namespace std;
int main()
{
	#ifndef OJ
	freopen("201909-1.txt","r",stdin);
	#endif
	int n;//����
	int m;//����
	int temp;	//�м����
	long  res=0;	//��������Ŀ
	cin>>n>>m;
	_rep(i,1,n)
	{
		cin>>num[i];
		_rep(j,1,m)
		{
			cin>>temp;
			if(temp<0)
				re[i]-=temp;
		}
		num[i]-=re[i];
	}
	_rep(i,1,n)
	{
		res+=num[i];
	}
	cout<<res<<" ";
	int max=re[1];
	int id=1;
	_rep(i,2,n)
	{
		if(max<re[i])
		{
			max=re[i];
			id=i;
		}
	}
	cout<<id<<" "<<max;
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
 
