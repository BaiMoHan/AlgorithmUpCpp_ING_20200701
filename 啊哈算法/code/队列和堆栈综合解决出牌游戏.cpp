//���кͶ�ջ���ۺ�ʹ��
#include<stdio.h>
#define N 101
//ֻ��9���ƣ����������Ҳֻ���˾����ƣ��ɴ�ȷ����ջ����ռ�
#define M 10 
//���ö��нṹ�壬��ʾ���е��� 
struct queue
{
	int data[N];//���д������ 
	int head;//���� 
	int tail;//��β 
 } ;
 struct stack
 {
 	int data[M];
 	int top; 
  } ;
  int main()
  {
  	struct queue q1,q2;
  	struct stack s;
  	int book[M];//������¼�����ϵ��ƣ��Ӷ��ж��Ƿ�Ӯ��
	int i,t;
	
	q1.head=1;q1.tail=1;//���г�ʼ�� 
	q2.head=1;q2.tail=1;//���г�ʼ��
	s.top=0;
	
	//��ʼ��������飬���������Щ���Ѿ�������
	for(i=1;i<=9;i++)
	{
		book[i]=0;//�������book[i]��ֵ���ж������Ƿ����� 
	 } 
	 
	 //���ƣ������
	 for(i=1;i<=6;i++)
	 {
	 	scanf("%d",&q1.data[q1.tail]);
	 	q1.tail++;
	  } 
	 for(i=1;i<=6;i++)
	 {
	 	scanf("%d",&q2.data[q2.tail]);
	 	q2.tail++;
	 }
	 
	 //��ʼ����
	 while(q1.head<q1.tail&&q2.head<q2.tail)
	 //����Ϊ��ʱ��������Ϸ����
	 {
	 	t=q1.data[q1.head];//q1�ȳ��ƣ����� 
		if(book[t])//�ж����������Ƿ��Ѵ����������� 
		{
			q1.head++;//���ƺ󣬶������� 
			q1.data[q1.tail]=t;//����ĸ�������� 
			q1.tail++;//��β���� 
			while(s.data[s.top]!=t)//һֱƥ�䵽���������е������� 
			{
				book[s.data[s.top]]=0;//Ҫ�����м���ŵ������ƣ����±��
				q1.data[q1.tail]=s.data[s.top--];//ջ����ͬʱ��� 
				q1.tail++;//ÿ����Ӻ󣬶�β���� 
			}
		 } 
		 else
		 {
		 	q1.head++;//���Ӻ�������� 
		 	book[t]=1;//ͬʱ��¼������� 
		 	s.data[++s.top]=t;//������ƣ�������ջ 
		 }
		 
		 t=q2.data[q2.head];//q1�����ƺ��ֵ�q2����
		 //������q1һ��,���ж��Ƿ�Ӯ��
		 if(book[t])
		 {
		 	q2.head++;//���Ӻ�������� 
		 	q2.data[q2.tail]=t;//Ӯ�������
			q2.tail++;//��Ӻ󣬶�β����
			while(s.data[s.top]!=t)//���м������ӣ���Ӯ��
			{
				book[s.data[s.top]]=0;//�û�������Ҫ���±�� 
				q2.data[q2.tail]=s.data[s.top--];//ջ����ͬʱ���
				q2.tail++;//ÿ����Ӻ󣬶�β���� 
			 } 
		 }
		 else//û��Ӯ�� 
		 {
		 	book[t]=1; 
		 	q2.head++;//���һ���ƺ󣬶�������
			s.data[++s.top]=t;//�Գ�������ջ 
		  } 
		  
	  } 
	  if(q1.head==q1.tail)
	  {
	  	printf("q2ȡ��ʤ��\n");
		printf("q2���е���Ϊ��\n");
		while(q2.head<q2.tail)
		{
			printf("%d ",q2.data[q2.head++]);
		 } 
	   } 
	  else
	  {
	  	printf("q1ȡ��ʤ��\n");
	  	printf("q1���е���Ϊ��\n");
	  	while(q1.head<q1.tail)
	  	{
	  		printf("%d ",q1.data[q1.head++]);
		  }
	  }
	  printf("���ϵ���Ϊ��\n");
	  for(i=1;i<=s.top;i++)
	  {
	  	printf("%d ",s.data[i]);
	   } 
	  
	  return 0;
	 
  }
 
