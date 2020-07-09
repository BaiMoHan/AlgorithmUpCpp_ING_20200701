//队列
#include<stdio.h>
int main()
{
	int n;
	
	int a[100]={0,6,3,1,7,5,8,9,2,4},*head,*tail;
	int i;
	head=a+1;//头指针指向第一个 
	tail=a+10;//尾指针指向数组末尾 
	while(head<tail)//队列不为空时进行解密操作
	{
		printf("%d ",*head);
		head++;//输出第一个值之后，头指针自增到下一位 
		*tail=*head;//将第二位数字入队 
		tail++;//尾指针自增到下次入队的空间 
		head++;//头指针自增指向下一次删除的数 
	 } 
	 return 0;
 } 
