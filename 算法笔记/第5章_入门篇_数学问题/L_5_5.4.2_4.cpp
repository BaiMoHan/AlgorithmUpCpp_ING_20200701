#include<stdio.h>
const int maxn=101;
int prime[maxn],pnum=0;
bool p[maxn]={0};
void FindPrime(){
	for(int i=2;i<maxn;i++){
		if(p[i]==false)//���i������ 
		{
			prime[pnum++]=i;//���뵽��������
			for(int j=i+i;j<maxn;j+=i)
				p[j]=true; 
		}
	}
}
int main(){
	FindPrime();//�ǵô˾䲻��©��
	for(int i=0;i<pnum;i++)
	{
		printf("%d ",prime[i]);
	 } 
}
