#include<iostream>
using namespace std;
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define OJ 98
int main()
{
	#ifndef OJ
	freopen("201509-1.txt","r",stdin);
	#endif
	int n;
	int res=0;
	int lastnum=0;
	int temp=0;
	cin>>n;
	cin>>lastnum;
	res++;
	_rep(i,1,n)
	{
		cin>>temp;
		if(temp!=lastnum)
		{
			lastnum=temp;
			res++;
		 } 
	}
	cout<<res;
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
