//�������ų���
#include<stdio.h>
#include<stdlib.h> 
//����һ���ṹ������ʾ����Ľ������
struct node
{
	int data;
	struct node *next;
 } ;
 int main()
 {
 	//qΪǰһ���ڵ㣬pΪ��ʱָ�룬tΪ������½ڵ� 
 	struct node *head ,*p,*q,*t;
 	int i,n,a;
 	scanf("%d",&n);//ȷ�������ж��ٸ���
	head=NULL;//ͷָ���ʼΪ��
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);//��ȡ�������
		//��̬����һ���ռ䣬�������һ�����
		//������ʱָ��pָ�������� 
		p=(struct node *)malloc(sizeof(struct node));
		p->data=a;//a������ֵ��
		p->next=NULL;
		//���õ�ǰ���ĺ��ָ��Ϊ��
		if(head==NULL)
		{
			head=p;
			//������ǵ�һ�������Ľ�㣬��ͷָ��ָ�������� 
		 }
		 else
		 {
		 	q->next=p;
		 	/*������ǵ�һ�������Ľ�㣬����һ�����
			 ��ͷָ��ָ��������*/ 
		  } 
		  q=p;
	}
		  //qÿ��ָ��ǰ��㣬����һ�δ���ʱ���Զ������ָ����һ����� 
	     //�������� 
	     scanf("%d",&a);//������������ 
	     t=head;//����ָ�룬������ͷ����ʼ 
	     while(t!=NULL)
		 //��û�е�������β����ʱ��ѭ��
		 {
		 	if(t->next->data>a)
		 	/*�����ǰ������һ�����������ڴ�����������˵��
			 ����Ӧ�ò�����һ���ڵ�*/ 
		 	{
		 		p=(struct node *)malloc(sizeof(struct node));
		 		p->data=a;
		 		p->next=t->next;
		 		//�������ָ��ǰ���ĺ��ָ��ָ��Ľ��
				t->next=p;
				//��ǰ���ĺ��ָ��ָ���������
				break;//��������˳�ѭ�� 
			 }
			 t=t->next;//������һ����� 
		  } 
		  
		  //��������е�������
		  t=head;
		  while(t!=NULL)
		  {
		  	printf("%d ",t->data);
		  	t=t->next;//������һ����� 
		   } 
		   return 0; 
	 
 }
