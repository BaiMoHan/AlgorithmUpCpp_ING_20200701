//�����ݵĵݹ�д��
typedef long long LL;
//�� a^b &m �ĵݹ�д��
LL binarypow(LL a,LL b,LL m)
{
	LL num; 
	if(b==0)	
		return 1; //a^0=1
	if(b%2==1)	
		return a*binarypow(a,b-1,m)%m; //Ϊ�˱��ڶ��֣����һ��a���ٶ��֣�ÿ�μ��㶼�������������
	else
	{
		//b��ż�����������ݴ�
		num=binarypow(a,b/2,m)%m;	//�������һ��ֵ���ݹ�������������ֵ�����͸��Ӷ� 
		return  num*num % m;
	 }	 
}
