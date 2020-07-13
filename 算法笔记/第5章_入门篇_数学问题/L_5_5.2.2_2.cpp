#include<cstdio>
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}
int lcm(int a,int b){
	int k=gcd(a,b);
	return a/k*b;
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d\n",lcm(a,b));
	}
	return 0;
}
