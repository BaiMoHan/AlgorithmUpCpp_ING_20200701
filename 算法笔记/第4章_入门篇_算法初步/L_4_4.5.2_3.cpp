//快速幂的递归写法
typedef long long LL;
//求 a^b &m 的递归写法
LL binarypow(LL a,LL b,LL m)
{
	LL num; 
	if(b==0)	
		return 1; //a^0=1
	if(b%2==1)	
		return a*binarypow(a,b-1,m)%m; //为了便于二分，提出一个a后再二分，每次计算都求摸，避免大数
	else
	{
		//b是偶数，二分求幂次
		num=binarypow(a,b/2,m)%m;	//先算出来一个值，递归调用再运用这个值，降低复杂度 
		return  num*num % m;
	 }	 
}
