#include<iostream>
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define OJ 98
using namespace std;
int main()
{
	#ifndef OJ
	freopen("201703-1.txt","r",stdin);
	#endif
	int n,k;
	cin>>n>>k;
	int res=0,now=0;
	int temp;
	_rep(i,0,n)
	{
		cin>>temp;
		if(i==n-1){
			res++;
			cout<<res;
		}else
		{
			if(now+temp>=k)
			{
				res++;
				now=0;
			}else{
				now+=temp;
			}
		}
	}
	
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
