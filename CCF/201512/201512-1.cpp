#include<iostream>
#define OJ 98
using namespace std;
int main()
{
	#ifndef OJ
	freopen("201512-1.txt","r",stdin);
	#endif
	long long n;
	cin>>n;
	long res=0;
	while(n!=0)
	{
		res+=n%10;
		n/=10;
	}
	cout<<res;
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
