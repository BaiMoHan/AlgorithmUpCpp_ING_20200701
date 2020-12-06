#include<iostream>
#include<algorithm>
#define _rep(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define OJ 98
using namespace std;
#define N 1003
struct node{
	int num;//钥匙编号
	int t;	//操作时刻 
}p1[N],p2[N];//p1为取钥匙，p2为还钥匙
int key[N];	//钥匙 
bool cmp(struct node a,struct node b)
{
	//按操作时间从小到大排序 
	if(a.t<b.t)
		return true;
	//操作时间相同就按照序号从小到大排序 
	else if(a.t==b.t)
		return a.num<b.num;
	else
		return false;
}
int main()
{
	#ifndef OJ
	freopen("201709-2.txt","r",stdin);
	#endif
	int n,k;
	cin>>n>>k;
	int w,s,c;
	_rep(i,1,n)
		key[i]=i;
	_rep(i,1,k)
	{
		cin>>w>>s>>c;
		//取 
		p1[i].num=w;
		p1[i].t=s;
		//还 
		p2[i].num=w;
		p2[i].t=s+c;
	 } 
	//对p1 p2排序 
	sort(p1+1,p1+1+k,cmp);
	sort(p2+1,p2+1+k,cmp);
	
	int i=1,j=1;
	while(i!=k+1&&j!=k+1)
	{
		//取还一起，或者还的时刻在前，都是先还 
		if(p1[i].t>=p2[j].t)
		{
			//先还
			_rep(z,1,n)
				if(key[z]==0)
				{
					key[z]=p2[j].num;
					j++;//移到到下一个p2
					break;
				} 
		 }else	//先取 
		 {
		 	_rep(z,1,n)
		 		if(key[z]==p1[i].num)
		 		{
		 			key[z]=0;
		 			i++;	//移到下一个 
		 			break;
				 }
		 }
	}
	
	//最后剩下的肯定是没有还的
	while(j<=k)
	{
		_rep(z,1,n)
		if(key[z]==0)
		{
			key[z]=p2[j].num;
			j++;//移到到下一个p2
			break;
		} 
	 } 
	
	_rep(z,1,n-1)
		cout<<key[z]<<" ";
	cout<<key[n];
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
