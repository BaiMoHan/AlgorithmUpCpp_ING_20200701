#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//����ָ����Χ����������
int main()
{
	int i;	//���������� 
	srand((unsigned)time(NULL));	//��ʼ�����������
	//rand()%(b-a+1)�ķ�Χ��[0.b-a]
	//rand()%(b-a+1)+a�ķ�Χ��[a,b]
	for(i=0;i<10;i++)
		printf("%d ",rand()%2);	//����[0,1]����������
	printf("\n");
	for(i=0;i<10;i++)
		printf("%d ",rand()%3+9);//����[9,11]���������� 
	return 0; 
 } 
