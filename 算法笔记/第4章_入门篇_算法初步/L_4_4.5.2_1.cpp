//二分法求根号2的近似值，利用函数f(x)=x^2
#include<stdio.h>
const double eps=1e-5;		//设置精度为10^-5
double function(double x);
double calSqrt(double left,double right);
int main()
{
	printf("%f",calSqrt(1,2));
	return 0; 
 } 
double function(double x)
{
	return x*x;
 } 
double calSqrt(double left,double right)
{
	double mid;					//区间中点 
	while(right-left>eps)		//比eps小意味着达到了精度，注意循环的大于号
	{
		mid=left+(right-left)/2;//求区间中点
		if(function(mid)>2)		//中点值大于根号2 
			right=mid;			//在[left,mid]区间里面找
		else
			left=mid;			//在[mid,right]区间继续逼近 
	 } 
	 return mid;				//夹出来的值即为根号2的接近值 
}
