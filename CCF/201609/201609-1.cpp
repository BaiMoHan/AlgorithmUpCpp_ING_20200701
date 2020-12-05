#include<iostream>
#include<cmath>
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define OJ 98
using namespace std;
int main()
{
	#ifndef OJ
	freopen("201609-1.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	int res=0;
	int lastnum,temp;
	cin>>lastnum>>temp;
	res=abs(lastnum-temp);
	lastnum=temp;
	_rep(i,2,n)
	{
		cin>>temp;
		res=res<abs(lastnum-temp)?abs(lastnum-temp):res;
		lastnum=temp;
	}
	cout<<res;
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
