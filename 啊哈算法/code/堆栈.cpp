//��ջ
#include<stdio.h>
#include<string.h>
int main()
{
	char a[101],s[101];
	//һ���Ǵ�Ŵ����ַ�����һ��������ջ 
	int len,i,top=0,mid,next;
	//top��Ϊ��ջ�ı�� 
	gets(a);
	len=strlen(a);//���ַ����ĳ��� 
	mid=len/2-1;//ȡ���ַ������м�λ�� 
	for(i=0;i<=mid;i++)
	//���ַ�����ǰ�벿����ջ,ע��i<=mid 
	{
		s[++top]=a[i];
		//��++top��Ϊ�˺������top=0���жϱȽ���ı�� 
	}
	//�ҳ��ַ����ĳ�������������ż��
	if(len%2)
	{
		next=mid+2;
		//�������ȵĴ����м��һλ����Ҫ�Ƚ�,������+2 
	}
	else
	{
		next=mid+1;
	 } 
	 //���ݶ�ջ�ĺ���ȳ����бȽ�
	 for(i=next;i<len;i++)
	 {
	 	if(a[i]!=s[top])
	 	{
	 		break;//���ǻ������У��˳�ѭ�� 
		 }
		 top--; 
	  } 
	  if(top==0)
	  {
	  	printf("%s�ǻ�������",a);
	  }
	  else
	  {
	  	printf("%s���ǻ�������",a); 
	  }
	  return 0;
 } 
