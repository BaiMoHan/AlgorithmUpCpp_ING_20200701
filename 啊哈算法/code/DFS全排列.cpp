#include<stdio.h>
int a[10],book[10],n;
//C����ȫ�ֱ���Ĭ�ϳ�ʼ��Ϊ0,aΪ���ӣ�book����ѷŵ��� 
void deep_first_search(int step);
int main()
{
	scanf("%d",&n);
	deep_first_search(1);//���ȴӵ�һ�����ӿ�ʼ����
	return 0; 
}
void deep_first_search(int step)//step��ʾվ�ڵڼ�������ǰ
{
	int i,count=1;//ѭ������
	if(step==n+1)//�ݹ������������ǰn�������Ѿ��ź��ˣ����һ��ȫ����
	{
		
		//���ȫ���к����1-n�ź����еı�� 
		for(i=1;i<=n;i++)
			printf("%d",a[i]);
		printf("\n");
		
		return ;//���һ��ȫ���к󷵻���һ�ε���deep_first_search�����ĵط�
		 
	} 
	 
	 //��ʱվ�ڵ�step������ǰ�棬����1,2,3,,,n��˳����
	 for(i=1;i<=n;i++)
	 {
	 	if(book[i]==0)//�ж�����������Ƿ��Ѿ�ʹ�� 
	 	{
		 	a[step]=i;
	 		book[i]=1;//������Ӻ󣬾ͱ��Ϊ1 
	 		printf("�ҷ�����%d\n",a[step]);
	 		//����������ɺ󣬼���ǰ�����Ѿ�����ã���һ�����ӵĴ���ʽ�뵱ǰһ�����ݹ����
			deep_first_search(step+1);
			book[i]=0;//�Ѹղų��Ե����ջأ��Ӷ���ʼ��һ�γ��ԣ��µ�ȫ���� 
			printf("�һ�����%d\n",i);
	 	}
	  } 
 } 
