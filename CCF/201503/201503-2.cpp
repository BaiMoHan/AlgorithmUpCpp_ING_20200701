#include<iostream>
#include<algorithm>
using namespace std;
#define OJ 98
#define N 1004
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
struct point{
	int count;	//出现的次数 
	int value;	//值 
}node[N];
bool cmp(struct point a,struct point b)
{
	//首先按照次数 
	if(a.count>b.count)
		return true;
	//再按照值 
	else if(a.count==b.count) 
		return a.value<b.value;
	else
		return false;
}
int main()
{
	#ifndef OJ
	freopen("201503-2.txt","r",stdin);
	#endif
	int n;	//数字数目
	cin>>n;
	int temp;
	_rep(i,0,n)
	{
		cin>>temp;
		node[temp].count++;
		node[temp].value=temp;
	}
	sort(node,node+N,cmp);
	_rep(i,0,n){
		if(node[i].value==0)
			break;
		cout<<node[i].value<<" "<<node[i].count<<endl;
	}
		
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
	 
}
