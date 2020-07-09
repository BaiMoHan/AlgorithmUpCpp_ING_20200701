//堆栈
#include<stdio.h>
#include<string.h>
int main()
{
	char a[101],s[101];
	//一个是存放待测字符串，一个用作堆栈 
	int len,i,top=0,mid,next;
	//top作为堆栈的标记 
	gets(a);
	len=strlen(a);//求字符串的长度 
	mid=len/2-1;//取出字符串的中间位置 
	for(i=0;i<=mid;i++)
	//将字符串的前半部分入栈,注意i<=mid 
	{
		s[++top]=a[i];
		//用++top是为了后面根据top=0来判断比较完的标记 
	}
	//找出字符串的长度是奇数还是偶数
	if(len%2)
	{
		next=mid+2;
		//奇数长度的串最中间的一位不需要比较,所以是+2 
	}
	else
	{
		next=mid+1;
	 } 
	 //根据堆栈的后进先出进行比较
	 for(i=next;i<len;i++)
	 {
	 	if(a[i]!=s[top])
	 	{
	 		break;//不是回文序列，退出循环 
		 }
		 top--; 
	  } 
	  if(top==0)
	  {
	  	printf("%s是回文序列",a);
	  }
	  else
	  {
	  	printf("%s不是回文序列",a); 
	  }
	  return 0;
 } 
