#include<stdio.h>
struct node{
	int x;//������
	int s;//ת������ 
};
int main()
{
	struct node que[2501];
	int e[51][51]={0},book[51]={0};
	int head,tail;
	int i,j,m,n,a,b,cur,start,end,flag=0;
	//���붥��������������㣬�յ� 
	scanf("%d %d %d %d",&n,&m,&start,&end);
	//��ʼ����ά����
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=99999999;
			
	//������к�����Ϣ
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		e[a][b]=1;
		e[b][a]=1;//�˴�Ϊ����ͼ 
	 } 
	 head=1;
	 tail=1;
	 que[tail].x=start;
	 que[tail].s=0;
	 tail++;//���г�ʼ��
	 book[start]=1;//���start�ų���
	 
	 //�����в�Ϊ�յ�ʱ��ִ��ѭ��
	 while(head<tail)
	 {
	 	cur=que[head].x;//��ǰ�������׳��еı��
		for(j=1;j<=n;j++)//��1~n���������ι������������Щ���п��Դӵ�ǰ���е��� 
		{
			if(e[cur][j]!=99999999&&book[j]==0)
			{
				//����ӳ���cur������j�к��ಢ���ж�j�Ƿ��Ѿ��ڶ�����
				que[tail].x=j;
				que[tail].s=que[head].s+1;//ת������Ϊ�丸���+1
				tail++;//��ɽ�����j��ӵĲ���
				book[j]=1;//���֮��Ҫ��� 
			}
			//�������Ŀ�������ֹͣ��չ
			if(que[tail-1].x==end)
			{
				flag=1;//flag�����������whileѭ������Ϊ���ж�����ֻ�������ڲ� 
				break;//����forѭ�� 
			 } 
		 } 
		 if(flag==1)
		 	break;//�ҵ�Ŀ�ĳ��У�������չ
		head++;//һ������չ������Ҫ���丸�ڵ���� 
	  } 
	  printf("���ٵ�ת������Ϊ%d",que[tail-1].s);
	  return 0;
}
