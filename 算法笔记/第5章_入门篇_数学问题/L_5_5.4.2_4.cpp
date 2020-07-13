#include<stdio.h>
const int maxn=101;
int prime[maxn],pnum=0;
bool p[maxn]={0};
void FindPrime(){
	for(int i=2;i<maxn;i++){
		if(p[i]==false)//如果i是素数 
		{
			prime[pnum++]=i;//加入到素数表中
			for(int j=i+i;j<maxn;j+=i)
				p[j]=true; 
		}
	}
}
int main(){
	FindPrime();//记得此句不能漏掉
	for(int i=0;i<pnum;i++)
	{
		printf("%d ",prime[i]);
	 } 
}
