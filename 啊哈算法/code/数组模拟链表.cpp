//������ģ������
#include<stdio.h>
#define N 101
int main()
{
	//����һ��������ݵ������һ��ָ�����õ����� 
	int data[N],right[N],n,i,a;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&data[i]);
		if(i!=n)//��ʼ��ָ�����õ�����right 
		{
			right[i]=i+1;
		 } 
		else
		{
			right[i]=0;//ĩβ���Ϊ0,����NULL 
		} 
	}
	printf("��������֮ǰ:\n");
	i=1;//��ͷ���� 
	while(i!=0)
	{
		printf("%d ",data[i]);
		i=right[i]; 
	 } 
	 printf("\n�����������µ�����");
	 scanf("%d",&a);
	 //�������ֵĲ��� 
	 i=1;//��ͷ���� 
	 n++;
	 while(i!=0)//������������Ϊright[i]=0 
	 {
	 	if(data[right[i]]>a)//�����ǰ������һ�������ڲ���������Ͳ��� 
	 	{
	 		data[n]=a;
	 		right[n]=right[i];
	 		right[i]=n;
	 		break;
		 }
		 else if(right[i]==0)
		 {
		 	data[n]=a;
		 	right[n]=0;
		 	right[i]=n;
		 	break;
		 } 
		 i=right[i];
	 }
	 i=1;//��ͷ���� 
	while(i!=0)
	{
		printf("%d ",data[i]);
		i=right[i];
	 } 
 } 
