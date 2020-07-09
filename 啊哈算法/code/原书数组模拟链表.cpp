#include<stdio.h>
int main()
{
	int data[101],right[101];
	int i,n,t,len;
	//读入已经有的数
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&data[i]);
	 } 
	 len=n;
	 //初始化数组right
	 for(i=1;i<=n;i++)
	 {
	 	if(i!=n)
	 	{
	 		right[i]=i+1;
		 }
		 else
		 {
		 	right[i]=0;//最后一位数没有下一位 
		 }
	 }
	 //直接在数组data的末尾加一个数字
	 len++;
	 scanf("%d",&data[len]);
	 
	 //从链表的头部开始遍历
	 t=1;
	 while(t!=0)
	 {
	 	if(data[right[t]]>data[len])
		 //如果当前结点下一个结点的值大于待插数，将数插到中间
		 {
		 	right[len]=right[t];
		 	right[t]=len;
		 	break;//插入完成，跳出循环 
		 } 
		 t=right[t];//指向下一位，相当于链表的p=p->next; 
	  } 
	  //输出链表的所有的数
	  t=1;
	  while(t!=0)
	  {
	  	printf("%d ",data[t]);
	  	t=right[t];
	   } 
	   return 0;
 } 
