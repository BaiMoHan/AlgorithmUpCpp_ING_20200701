//队列和堆栈的综合使用
#include<stdio.h>
#define N 101
//只有9中牌，桌面上最多也只放了九张牌，由此确定堆栈所需空间
#define M 10 
//设置队列结构体，表示手中的牌 
struct queue
{
	int data[N];//队列存放数据 
	int head;//队首 
	int tail;//队尾 
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
  	int book[M];//用来记录桌面上的牌，从而判断是否赢牌
	int i,t;
	
	q1.head=1;q1.tail=1;//队列初始化 
	q2.head=1;q2.tail=1;//队列初始化
	s.top=0;
	
	//初始化标记数组，用来标记哪些牌已经在桌上
	for(i=1;i<=9;i++)
	{
		book[i]=0;//后面根据book[i]的值来判断桌上是否有牌 
	 } 
	 
	 //发牌，即入队
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
	 
	 //开始出牌
	 while(q1.head<q1.tail&&q2.head<q2.tail)
	 //队列为空时，代表游戏结束
	 {
	 	t=q1.data[q1.head];//q1先出牌，出队 
		if(book[t])//判断所出的牌是否已存在于桌面上 
		{
			q1.head++;//出牌后，队首自增 
			q1.data[q1.tail]=t;//打出的该牌先入队 
			q1.tail++;//队尾自增 
			while(s.data[s.top]!=t)//一直匹配到桌面上已有的那张牌 
			{
				book[s.data[s.top]]=0;//要回收中间夹着的所有牌，重新标记
				q1.data[q1.tail]=s.data[s.top--];//栈弹出同时入队 
				q1.tail++;//每次入队后，队尾自增 
			}
		 } 
		 else
		 {
		 	q1.head++;//出队后队首自增 
		 	book[t]=1;//同时记录打出的牌 
		 	s.data[++s.top]=t;//打出的牌，桌面入栈 
		 }
		 
		 t=q2.data[q2.head];//q1出完牌后轮到q2出牌
		 //过程与q1一样,先判断是否赢牌
		 if(book[t])
		 {
		 	q2.head++;//出队后队首自增 
		 	q2.data[q2.tail]=t;//赢牌先入队
			q2.tail++;//入队后，队尾自增
			while(s.data[s.top]!=t)//将中间的牌入队，即赢牌
			{
				book[s.data[s.top]]=0;//拿回来的牌要重新标记 
				q2.data[q2.tail]=s.data[s.top--];//栈弹出同时入队
				q2.tail++;//每次入队后，队尾自增 
			 } 
		 }
		 else//没有赢牌 
		 {
		 	book[t]=1; 
		 	q2.head++;//打出一次牌后，队首自增
			s.data[++s.top]=t;//对出的牌入栈 
		  } 
		  
	  } 
	  if(q1.head==q1.tail)
	  {
	  	printf("q2取得胜利\n");
		printf("q2手中的牌为：\n");
		while(q2.head<q2.tail)
		{
			printf("%d ",q2.data[q2.head++]);
		 } 
	   } 
	  else
	  {
	  	printf("q1取得胜利\n");
	  	printf("q1手中的牌为：\n");
	  	while(q1.head<q1.tail)
	  	{
	  		printf("%d ",q1.data[q1.head++]);
		  }
	  }
	  printf("桌上的牌为：\n");
	  for(i=1;i<=s.top;i++)
	  {
	  	printf("%d ",s.data[i]);
	   } 
	  
	  return 0;
	 
  }
 
