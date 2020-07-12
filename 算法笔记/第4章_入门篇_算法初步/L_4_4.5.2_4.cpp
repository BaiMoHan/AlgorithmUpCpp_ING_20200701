//快速幂的迭代写法
typedef long long LL;
LL binarypow(LL a,LL b,LL m)
{
	LL ans=1;
	while(b>0)
	{
		if(b&1)		//如果b的二进制末尾为1 
		{
			ans=ans*a%m;	//把二进制中为1的数全乘起来 
		}
		a=a*a%m;	//下一位为当前位的平方，从数值大小上
		b>>=1;		//b的二进制向右移动一位，也可以b/=2 
	}
	return ans; 
 } 
