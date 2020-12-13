#include<iostream>
using namespace std;
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define R 1000000007
#define N 1003
long long dp[N][7];
/*
s1:ֻ����2
s2:ֻ����2 0����0���ǵ�һ���� 
s3:ֻ����2 3����2��3��ǰ��
s4:ֻ����2 0 1����0��1��ǰ�棬0���ǵ�һ���� 
s5:ֻ����2 0 3����2��3��ǰ�棬0���ǵ�һ���� 
s6:����0 1 2 3������������ 
*/
int main()
{
	#ifndef OJ
	freopen("201312-4.txt","r",stdin);
	#endif
	dp[1][1]=1;
	int n;
	cin>>n;
	_rep(i,2,n+1)
	{
		//ֻ����2�ĸ�������λ���ĸ��� 
		dp[i][1]=dp[i-1][1]; 
		//������S1�ٲ�λ0��i-1λ��S2��0 ����2 
		dp[i][2]=(dp[i-1][1]+2*dp[i-1][2])%R;
		//��i-1λS3��3,i-1λS1��3 
		dp[i][3]=(dp[i-1][3]+dp[i-1][1])%R;
		//��i-1λS2��3,��i-1λS4��1��0 
		dp[i][4]=(2*dp[i-1][4]+dp[i-1][2])%R; 
		//��i-1λS5��0��3,��i-1λS3��0,��i-1λS2��3 
		dp[i][5]=(2*dp[i-1][5]+dp[i-1][3]+dp[i-1][2])%R;
		//��i-1λS6��1��3,��i-1λS4��3����i-1λS5��1 
		dp[i][6]=(2*dp[i-1][6]+dp[i-1][4]+dp[i-1][5])%R;
	 } 
	cout<<dp[n][6];
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
