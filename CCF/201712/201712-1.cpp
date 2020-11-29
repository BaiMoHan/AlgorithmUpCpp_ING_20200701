#include<iostream>
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define OJ 98
#include<algorithm>
using namespace std;
int a[1003];
int main()
{
	#ifndef OJ
	freopen("201712-1.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	_rep(i,0,n)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int min=0x3f3f3f3f;
	_rep(i,0,n-1)
	{
		if((a[i+1]-a[i])<min)
			min=a[i+1]-a[i]; 
	}
	cout<<min;
	#ifndef OJ
	fclose(stdin);
	#endif
}
 
