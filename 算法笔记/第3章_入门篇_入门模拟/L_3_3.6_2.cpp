//PAT_B1009˵���� 
#include<cstdio>
#include<cstring>
int main()
{
	char str[90];
	int i;//�ܳ��Ȳ�����80
	while(gets(str)!=NULL)
	{
		for(i=0;str[i]!='\0';i++);//�������ַ���ĩβ
		//������� 
		for(i=i-1;i>=0;i--)
			printf("%c",str[i]);
		//�����Ϻ����һ������
		printf("\n"); 
	 } 
	 return 0;
}
