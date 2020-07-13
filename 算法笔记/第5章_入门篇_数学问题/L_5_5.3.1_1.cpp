//分数化简
#include<cstdio>
#include<cmath>
struct Fraction{
	int up,down;
}; 
Fraction reduction(Fraction result){
	if(result.down<0){	//分母为负，令分子和分母都变成相反数
		result.up=-result.up;
		result.down=-result.down; 
	}
	if(result.up==0){	//分子为0,分母为1 
		result.down=1;
	}else{	//分数不为0就约分 
		int d=gcd(abs(result.up),abs(result.down));//求最大公约数，注意求绝对值
		result.up/=d;
		result.down/=d; 
	}
	return result;
}
