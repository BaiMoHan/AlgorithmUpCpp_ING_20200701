//Ͱ���� 
#include<stdio.h>
#define M 50
int main()
{
	int book[M+1];
	int i,x,N;
	for(i=0;i<M+1;i++)
	{
		book[i]=0;//��ʼ��ÿ������Ӧ��λ��Ϊ0 
	 } 
	 scanf("%d",&N);
	 for(i=0;i<N;i++)
	 {
	 	scanf("%d",&x);
	 	book[x]++;//��Ӧλ�õ������� 
	 }
	 for(i=0;i<M+1;i++)
	 {
	 	while(book[i])//�������ǵ����� 
	 	{
	 		printf("%d ",i);
	 		book[i]--;//������һ�����ֺ�ͼ����ݼ� 
		 }
	  } 
	  return 0;
}
