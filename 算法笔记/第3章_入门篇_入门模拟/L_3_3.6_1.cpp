//codeup_5901_���Ĵ�
#include<cstdio>
#include<cstring>
const int maxn=256;
//�ж��ַ���str�Ƿ�Ϊ"���Ĵ�"
bool judge(char str[])
{
	int len=strlen(str);//���ַ�������
	for(int i=0;i<len/2;i++)
	{
		//iö���ַ�����ǰһ��
		 if(str[i]!=str[len-1-i])
		 	return false;//���ǻ��Ĵ� 
	 } 
	 return true;//�ǻ��Ĵ� 
 } 
 int main()
 {
 	char str[maxn];
 	while(gets(str))
 	{
 		//�����ַ���
		 bool flag=judge(str);
		 if(flag)
		 	printf("YES\n");
		 else
		 	printf("NO\n"); 
	 }
	 return 0;
 }
 
