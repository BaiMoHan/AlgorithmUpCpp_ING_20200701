#include<stdio.h>
int h[101],n;//������������ȫ��������nΪ����Ԫ�ظ���
void swap(int x,int y);//���x����y���н���
void siftdown(int i);//�ӽ��i��ʼ���µ���
void creat();//�����ѵĺ��� 
void heapsort();//��������
int main()
{
	int num,i;
	//��ȡ����Ԫ�ظ���
	 scanf("%d",&num);
	 //�������Ԫ��
	 for(i=1;i<=num;i++)
	 	scanf("%d",&h[i]);
	n=num;//Ԫ�صĸ������������ı�,num����ѭ�������� 
	creat();//������ 
	//������
	heapsort();
	//���������ֵ
	for(i=1;i<=num;i++)
		printf("%d ",h[i]); 
	 return 0;
 } 
 void swap(int x,int y)
 {
 	int temp;
 	temp=h[x];
 	h[x]=h[y];
 	h[y]=temp;
  } 
  void siftdown(int i)//�˴������µ���������Ϊ�˽������� 
  {
  	int t,flag=0;//t����ȷ���Ƿ���Ҫ������flag��������Ƿ��ں��ʵĸ���㴦 
    while(i*2<=n && 0==flag)
	{
		t=i;//��ʼ��ֵ��ͬ�ı�� 
		//�ܽ���ѭ��˵�������һ�����ڣ���������ӱȽ�
		if(h[i]<h[2*i])
		{
			t=2*i;//�������Ľ���� 
		 } 
		//�ж��Ƿ����Ҷ���
		if(2*i+1<=n)
		{
			//���Ҷ��ӽ��бȽ�
			if(h[t]<h[i*2+1]) 
			{
				t=i*2+1;//�������Ľ���� 
			 } 
		 } 
		 if(t!=i)//�����˵����Ҫ����
		 {
		 	swap(i,t);//�������ڵ�
			i=t;//���������µ�����Ԫ�صı��Ҳ���� 
		  } 
		  else
		  	flag=1;//����Ҫ������˵����Ԫ���Ѿ����ں��ʵĸ���㴦 
	 } 
	 return ; 
  }
  void heapsort()
  {
  	//������ÿ�ν��Ѷ������һ���������������µ���
	  while(n>1)//ע��˴���ʣ�����һ�����ŵ��Ѷ��Զ�����С�ģ�ѭ������Ϊֻʣһ��Ԫ�� 
	  {
	  	swap(1,n);
	  	n--;
	  	siftdown(1);
	   } 
	   return ;
   } 
   void creat()
   {
   	//�����ѵĺ�����ÿ�������������ѣ��Ӷ�������Ҳ����
	   int i;
	   for(i=n/2;i>=1;i--)
	   {
	   		siftdown(i);
		} 
		return ;
   }
  
  
