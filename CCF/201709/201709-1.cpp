#include<iostream>
#define OJ 98
using namespace std;
int main()
{
	#ifndef OJ
	freopen("201709-1.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	int num;	//单买可以购买多少瓶
	num=n/10;
	int res=0;
	int temp=0;
	temp=num/5;
	res+=temp*5;
	res+=temp*2;
	num-=temp*5;
	temp=num/3;
	res+= temp;
	res+=temp*3;
	num-=temp*3;
	res+=num;
	cout<<res;
	
	#ifndef OJ 
	fclose(stdin);
	#endif
	return 0;
 } 
