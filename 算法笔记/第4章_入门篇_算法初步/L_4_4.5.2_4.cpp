//�����ݵĵ���д��
typedef long long LL;
LL binarypow(LL a,LL b,LL m)
{
	LL ans=1;
	while(b>0)
	{
		if(b&1)		//���b�Ķ�����ĩβΪ1 
		{
			ans=ans*a%m;	//�Ѷ�������Ϊ1����ȫ������ 
		}
		a=a*a%m;	//��һλΪ��ǰλ��ƽ��������ֵ��С��
		b>>=1;		//b�Ķ����������ƶ�һλ��Ҳ����b/=2 
	}
	return ans; 
 } 
