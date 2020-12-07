#include<iostream>
#include<algorithm>
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define OJ 98
using namespace std;
#define N 1004
struct Node{
	int v;
	int t;
}node[N];
int book[N];
bool cmp(struct Node a,struct Node b)
{
	return a.v>b.v;
}
int main()
{
	#ifndef OJ
	freopen("201612-1.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	int temp; 
	_rep(i,0,n)
	{
		cin>>temp;
		node[temp].t++;
		node[temp].v=temp;
	}
	sort(node,node+1004,cmp);
	if(node[1].v==0)
	{
		cout<<node[0].v;
		#ifndef OJ
		fclose(stdin);
		#endif
		return 0;
	}
	//找到共有多少个数
	_rep(i,1,n)
	{
		if(node[i].v==0)
			break;
		book[i]=book[i-1]+node[i-1].t;
	}
	_rep(i,1,n)
	{
		if(book[i]==0)
			break;
		if(book[i]==n-book[i]-node[i].t)
		{
			cout<<node[i].v;
			#ifndef OJ
			fclose(stdin);
			#endif
			return 0;
		}
			
	}
	cout<<"-1";
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
