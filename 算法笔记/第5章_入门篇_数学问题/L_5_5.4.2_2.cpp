#include<stdio.h>
#include<math.h>
bool isPrime(int n){
	if(n<=1)
		return false;
	for(int i=2;i*i<=n;i++)
	{
		if(!(n%i))
			return false;
	}
	return true;
}
int prime[101],pnum=0;
bool p[101]={0};
void Find_Prime(){	//求素数表
	for(int i=1;i<101;i++){
		if(isPrime(i)==true){
			prime[pnum++]=i;
			p[i]=true;
		}
	} 
}
int main(){
	Find_Prime();//容易忘写
	for(int i=0;i<pnum;i++){
		printf("%d ",prime[i]);
	} 
	return 0;
}
