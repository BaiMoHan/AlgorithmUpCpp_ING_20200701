#include<cstdio>
int gcd(int a,int b)//�����Լ����շת������ĵݹ�д��
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
