//quick����
#include<stdio.h>
#define N 100
int count[N+1],n;//����ȫ�ֱ����������Ӻ�������ʱ������ָ��
void quicksort(int left,int right);
//��һ�����������ڱ����ڶ������������ڱ� 
int main()
{
	int i;
	scanf("%d",&n);//��ȡ�������ֵĸ���
	for(i=1;i<n+1;i++)
	{
		scanf("%d",&count[i]);
	 } 
	 quicksort(1,n);
	for(i=1;i<n+1;i++)
	{
		printf("%d ",count[i]);
	}
	return 0;
 } 
 void quicksort(int left,int right)
 {
 	int i,j,t,pivot;//���������ڱ� 

 	if(left>right)
	 //����õ�ĩ̬��������ָ��λ���غϣ�����һ�λ�����ƶ������i>j 
 		return ;
 		
 	i=left;
 	j=right;
	pivot=count[right];//ѡȡ���ұߵ�����Ϊ��׼
 	
 	while(i!=j)
 	{
	 	while(count[i]<=pivot&&i<j)
		 //˳�����Ҫ�����ұ�Ϊ��׼�����ȴ�Ѱ����߱�pivot����� 
		 i++;		
 		while(count[j]>=pivot&&i<j)//Ѱ���ұ߱�pivotС���� 
		 j--;
			
		
		
		if(i<j)
		{
			t=count[i];
			count[i]=count[j];
			count[j]=t; 
		}	
	  } 
	  count[right]=count[i];
	  count[i]=pivot;
	  quicksort(left,i-1);
	  //���������ַ��������ұߵģ��ݹ� 
	  quicksort(i+1,right);
	  //���������ַ���������ߵģ��ݹ� 	
 }
