//链表入门尝试
#include<stdio.h>
#include<stdlib.h> 
//创建一个结构体来表示链表的结点类型
struct node
{
	int data;
	struct node *next;
 } ;
 int main()
 {
 	//q为前一个节点，p为临时指针，t为加入的新节点 
 	struct node *head ,*p,*q,*t;
 	int i,n,a;
 	scanf("%d",&n);//确认输入有多少个数
	head=NULL;//头指针初始为空
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);//读取输入的数
		//动态申请一个空间，用来存放一个结点
		//并用临时指针p指向这个结点 
		p=(struct node *)malloc(sizeof(struct node));
		p->data=a;//a放在数值域
		p->next=NULL;
		//设置当前结点的后继指针为空
		if(head==NULL)
		{
			head=p;
			//如果这是第一个创建的结点，则将头指针指向这个结点 
		 }
		 else
		 {
		 	q->next=p;
		 	/*如果不是第一个创建的结点，则将上一个结点
			 的头指针指向这个结点*/ 
		  } 
		  q=p;
	}
		  //q每次指向当前结点，到下一次处理时就自动变成了指向上一个结点 
	     //插入数字 
	     scanf("%d",&a);//读入待插入的数 
	     t=head;//遍历指针，从链表头部开始 
	     while(t!=NULL)
		 //当没有到达链表尾部的时候循环
		 {
		 	if(t->next->data>a)
		 	/*如果当前结点的下一个结点的数大于待插入数，则说明
			 该数应该插在下一个节点*/ 
		 	{
		 		p=(struct node *)malloc(sizeof(struct node));
		 		p->data=a;
		 		p->next=t->next;
		 		//新增结点指向当前结点的后继指针指向的结点
				t->next=p;
				//当前结点的后继指针指向新增结点
				break;//插入完毕退出循环 
			 }
			 t=t->next;//继续下一个结点 
		  } 
		  
		  //输出链表中的所有数
		  t=head;
		  while(t!=NULL)
		  {
		  	printf("%d ",t->data);
		  	t=t->next;//继续下一个结点 
		   } 
		   return 0; 
	 
 }
