#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i; 
	srand((unsigned)time(NULL));	//��ʼ�����������
	for(i=0;i<10;i++)	//����[10000,60000]�ڵ������ 
		printf("%d ",(int)(1.0*rand()/RAND_MAX*50000+10000));
	return 0;
 } 
