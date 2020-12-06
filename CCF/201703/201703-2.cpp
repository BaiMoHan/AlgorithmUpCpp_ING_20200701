#include<iostream>
#define _rep(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define OJ 98
int q[1003];
using namespace std;
int main()
{
	#ifndef OJ
	freopen("201703-2.txt","r",stdin);
	#endif
	int n,k;
	cin>>n>>k;
	//³õÊ¼»¯ 
	_rep(i,1,n)
		q[i]=i;
	int num,step,id=0;
	_rep(i,1,k)
	{
		cin>>num>>step;
		if(step>0)
		{
			_rep(i,1,n)
				if(q[i]==num)
				{
					id=i;
					break;
				}
			_rep(i,1,step)
			{
				q[id+i-1]=q[id+i];
			}
			q[id+step]=num;
		}else{
			_rep(i,1,n)
				if(q[i]==num)
				{
					id=i;
					break;
				}
			_rep(i,1,-step)
			{
				q[id-i+1]=q[id-i];
			}
			q[id+step]=num;
		}
	}
	_rep(i,1,n)
		cout<<q[i]<<" ";
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
