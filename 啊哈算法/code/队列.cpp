//����
#include<stdio.h>
int main()
{
	int n;
	
	int a[100]={0,6,3,1,7,5,8,9,2,4},*head,*tail;
	int i;
	head=a+1;//ͷָ��ָ���һ�� 
	tail=a+10;//βָ��ָ������ĩβ 
	while(head<tail)//���в�Ϊ��ʱ���н��ܲ���
	{
		printf("%d ",*head);
		head++;//�����һ��ֵ֮��ͷָ����������һλ 
		*tail=*head;//���ڶ�λ������� 
		tail++;//βָ���������´���ӵĿռ� 
		head++;//ͷָ������ָ����һ��ɾ������ 
	 } 
	 return 0;
 } 
