#include<iostream>
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
int count;
int num;
int p[1004];
using namespace std;
int main()
{
	#ifndef OJ
	freopen("201712-2.txt","r",stdin);
	#endif
	int n,k;
	cin>>n>>k;
	bool flag=false;
	num=1;
	while(true)
	{
		_rep(i,1,n)
		{
			if(p[i])
			{
				continue;
			}
			if(num%k==0||num%10==k)
			{
				p[i]=1;
				count++;
			}
			if(count==n-1)
			{
				flag=true;
				break;
			}
			num++;	
		}
		if(flag==true)
			break;
	}
	_rep(i,1,n)
	{
		if(p[i]==0)
		{
			cout<<i;
			break;
		}
	}
	
	#ifndef OJ
	fclose(stdin);
	#endif
	
	return 0;
}
