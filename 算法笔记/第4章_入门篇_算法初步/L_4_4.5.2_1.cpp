//���ַ������2�Ľ���ֵ�����ú���f(x)=x^2
#include<stdio.h>
const double eps=1e-5;		//���þ���Ϊ10^-5
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
	double mid;					//�����е� 
	while(right-left>eps)		//��epsС��ζ�Ŵﵽ�˾��ȣ�ע��ѭ���Ĵ��ں�
	{
		mid=left+(right-left)/2;//�������е�
		if(function(mid)>2)		//�е�ֵ���ڸ���2 
			right=mid;			//��[left,mid]����������
		else
			left=mid;			//��[mid,right]��������ƽ� 
	 } 
	 return mid;				//�г�����ֵ��Ϊ����2�Ľӽ�ֵ 
}
