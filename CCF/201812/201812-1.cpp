#include<iostream>
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);a++)
#define OJ 98
using namespace std;
#define N 102
int main()
{
	#ifndef OJ
	freopen("201812-1.txt","r",stdin);
	#endif
	int res=0;
	int r,y,g,n;
	int k,v;
	cin>>r>>y>>g>>n; 
	_rep(i,0,n)
	{
		cin>>k>>v;
		switch(k){
			case 0:res+=v;break;
			case 1:res+=v;break;
			case 2:res+=v;res+=r;break;
			case 3:break;	
		}
	}
	cout<<res;
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
