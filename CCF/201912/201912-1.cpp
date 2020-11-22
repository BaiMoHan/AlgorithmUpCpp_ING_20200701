#include<iostream>
#define OJ 98
using namespace std;
bool judge(int i)
{
	if(i%7==0)
		return true;
	else
	{
		while(i!=0)
		{
			if(i%10==7)
				return true;
			i/=10;
		}
		return false;
	}
}
int main()
{
	#ifndef OJ
	freopen("201912-1.txt","r",stdin);
	#endif
	int n;
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	int count=0;
	int i=1;
	cin>>n;
	while(count<n)
	{
		switch(i%4){
			case 0:
				if(judge(i))
				{
					d++;
					i++;
					break;
				}
				else
				{
					count++;
					i++;
					break;
				} 
			case 1:
				if(judge(i))
				{
					a++;
					i++;
					break;
				}
				else
				{
					count++;
					i++;
					break;
				} 
			case 2:
				if(judge(i))
				{
					b++;
					i++;
					break;
				}
				else
				{
					count++;
					i++;
					break;
				}
			case 3:
				if(judge(i))
				{
					c++;
					i++;
					break;
				}
				else
				{
					count++;
					i++;
					break;
				}  
		}
	}
	cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
