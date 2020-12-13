#include<iostream>
using namespace std;
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define R 1000000007
#define N 1003
long long dp[N][7];
/*
s1:只包含2
s2:只包含2 0，且0不是第一个数 
s3:只包含2 3，且2在3的前面
s4:只包含2 0 1，且0在1的前面，0不是第一个数 
s5:只包含2 0 3，且2在3的前面，0不是第一个数 
s6:包含0 1 2 3，且满足条件 
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
		//只包含2的个数就是位数的个数 
		dp[i][1]=dp[i-1][1]; 
		//可以由S1再补位0，i-1位的S2补0 或者2 
		dp[i][2]=(dp[i-1][1]+2*dp[i-1][2])%R;
		//由i-1位S3补3,i-1位S1补3 
		dp[i][3]=(dp[i-1][3]+dp[i-1][1])%R;
		//由i-1位S2补3,由i-1位S4补1或0 
		dp[i][4]=(2*dp[i-1][4]+dp[i-1][2])%R; 
		//由i-1位S5补0或3,由i-1位S3补0,由i-1位S2补3 
		dp[i][5]=(2*dp[i-1][5]+dp[i-1][3]+dp[i-1][2])%R;
		//由i-1位S6补1或3,由i-1位S4补3，由i-1位S5补1 
		dp[i][6]=(2*dp[i-1][6]+dp[i-1][4]+dp[i-1][5])%R;
	 } 
	cout<<dp[n][6];
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
