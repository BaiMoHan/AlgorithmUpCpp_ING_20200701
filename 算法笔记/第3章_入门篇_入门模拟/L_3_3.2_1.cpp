//codeup_1934_��X 
#include<cstdio>
const int maxn=201;
int a[201];
int main()
{
	int n;
	//��ȡҪ�����n���� 
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		//�����������ŵ�������
		scanf("%d",&a[i]); 
	}
	//������������
	int x;
	//��ȡ��Ҫ���ҵ��� 
	scanf("%d",&x); 
	for(int i=0;i<n;i++)
	{
		if(x==a[i])
		{
			printf("%d",i);
			return 0;//�ҵ����������ֱ���˳� 
		}
	 } 
	 printf("-1");
	 return 0; 
}
