#include<cstdio>
int gcd(int a,int b)//求最大公约数的辗转相除法的递归写法
{
	if(!b)
		return a;
	else 
		return gcd(b,a%b);
 } 
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		printf("%d\n",gcd(m,n));
	}
	return 0;
}
