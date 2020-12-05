#include<iostream>
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define OJ 98
using namespace std;
int main()
{
	#ifndef OJ
	freopen("201604-1.txt","r",stdin);
	#endif
	bool flag;//false表示下降，true表示上升
	int n;
	int lastnum,temp;
	int res=0;
	cin>>n; 
	cin>>lastnum;
	cin>>temp;
	flag=temp>lastnum;
	lastnum=temp;
	_rep(i,2,n)
	{
		cin>>temp;
		if(flag!=temp>lastnum)
		{
			res++;
			flag=temp>lastnum;
		}
		lastnum=temp;
	}
	cout<<res;
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
