#include<stdio.h>
int book[50][50],max,sum,end,m,n; 
char map[50][50];
struct node{
	int x;//������ 
	int y;//������ 
	int f;//�丸�� 
	int s;//���� 
}que[50],stack[20]; 
void breadth_first_search(int x,int y);//����������� 
int count(int x,int y);//ͳ��ը���˺���
int main()
{
	int i,j,startx,starty,top=0;
	//�����ͼ��Ϣ
	scanf("%d %d %d %d",&m,&n,&startx,&starty);
	for(i=0;i<m;i++)
		{
		scanf("%s",map[i]);
	}

	max=count(startx,starty);
	breadth_first_search(startx,starty); 
	printf("���ɱ����Ϊ%d��\n",max);
	printf("Ӧ�ý�ը���˷���(%d,%d)��\n",que[end].x,que[end].y); 
	//��ʼ��ӡ·��
	while(end!=-1)
	{
		stack[top++]=que[end];//��ջ
		end=que[end].f; 
	 } 
	 printf("����·��Ϊ��\n"); 
	 while(top>=0)//��ջ��ӡ
	 {
	 	printf("��%d,%d��->\n",stack[top].x,stack[top].y);
	 	top--;
	  } 
	 
	return 0;
 } 
 void breadth_first_search(int x,int y)
 {
 	int head=0,tail=0,k,tx,ty;
 	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
 	que[0].x=x;
 	que[0].y=y;
 	que[0].f=-1;
 	que[0].s=0; 
 	tail++;//��ʼλ�����
	book[x][y]=1; //��ǳ�ʼλ�� 
	while(head<tail)
	{
		//�Ը��׿ɴ�ط��ĸ�������� 
		for(k=0;k<=3;k++)
		{
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			
			//�ж��Ƿ�Խ��
			if(tx<0||ty<0||tx>m-1||ty>n-1)
				continue;
			//�ж�·���Ƿ�ɴ�
			if(map[tx][ty]=='.'&&book[tx][ty]==0)
			{
				book[tx][ty]=1;//����Ѿ��ﵽ�Ľ��
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].f=head;//ָ���ף�������� 
				que[tail].s=que[head].s+1;
				tail++;//��Ӳ���
				sum=count(tx,ty);//����ɱ���� 
				if(sum>max)
				{
					max=sum;
					end=tail;//�洢Ŀ���ɱ����λ�� 
				}
			 } 
		}
			 head++;//ÿ���ĸ����������󣬸��׳��ӣ�������һ����չ 
	}
		return ; 
	}

int count(int x,int y)
{
	int k=0,tx,ty;
	//���水���������ϵ�˳������ͳ��ɱ����
	//ÿ��ͳ��ǰ����Ҫ��������
	tx=x;
	ty=y;
	while(map[tx][ty]!='#')
	{
		if(map[tx][ty]=='G')
			k++;
		ty++;
	 } 
	 
	 tx=x;
	 ty=y;
	 while(map[tx][ty]!='#')
	 {
	 	if(map[tx][ty]=='G')
	 		k++;
	 	tx++;
	 }
	 
	 tx=x;
	 ty=y;
	 while(map[tx][ty]!='#')
	 {
	 	if(map[tx][ty]=='G')
	 		k++;
	 	ty--;
	 }
	 
	 tx=x;
	 ty=y;
	 while(map[tx][ty]!='#')
	 {
	 	if(map[tx][ty]=='G')
	 		k++;
	 	tx--;
	 }
	 
	 return k;
}
