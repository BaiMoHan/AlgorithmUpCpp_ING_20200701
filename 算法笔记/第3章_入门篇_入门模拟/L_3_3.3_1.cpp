//PAT_B1036_���°���һ����
#include<cstdio>
int main()
{
	int row,col,k;//�У���
	char c;
	//���������ʹ�ӡ���ַ�
	scanf("%d %c",&col,&c);
	//������������ż���жϴ�ӡ������
	if(col%2)
		//�����������
		row=col/2+1;
	else
		row=col/2; 
	//��ʼ��ӡͼ�Σ���һ�������ж���ӡ
	for(int i=1;i<=col;i++)
		printf("%c",c);
	printf("\n\n");
	for(k=2;k<row;k++)
	{
		printf("%c",c);//�ȴ�ӡ�����ַ�c
		for(int i=0;i<col-2;i++)//��ӡcol-2���ո�
			printf(" ");
		printf("%c\n",c);//ĩβ��ӡһ���ո� 
		printf("\n");//�м��һ�� 
	 } 
	 //���һ��ȫ����ӡ
	 for(int i=1;i<=col;i++)
	 	printf("%c",c); 
 } 
