#include<stdio.h>
struct note
{
	int x;//�ź����� 
	int y;//�������� 
	int f;//���ø����ڶ����еı�ţ��Ա��ӡ·��
	int s;//��Ų��� 
 }que[2501],stack[10];//���ǵ���ͼ���Ϊ50X50,��չ���ᳬ��2500
 int main() 
 {
 	int map[51][51]={0},book[51][51]={0};
 	//map����������ŵ�ͼ״����book������������Ѿ��߹��ĵ�
	int i,j,k,n,m,p,q,startx,starty,tx,ty,head,tail,flag;
	int next[4][2]={{0,1},{1,0},{0,-1},{0,-1}};
	//��Ӧ�������ϵ�����ı�˳��
	//�����ͼ״��
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	 for(j=1;j<=m;j++)
	  scanf("%d",&map[i][j]);
	//�����ʼλ����Ŀ��λ�� 
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	//���г�ʼ��
	head=1;tail=1;
	que[tail].x=startx;
	que[tail].y=starty;
	que[tail].s=0;
	que[tail].f=0;
	tail++; 
	book[startx][starty]=1;//��ʼλ��Ҫ��ǣ������ظ���չ
	flag=0;//��������Ƿ�ﵽĿ�ĵأ�1Ϊ�Ѵﵽ
	while(head<tail)//���в�Ϊ�յ�ʱ��ѭ�� 
	{
		//ö���ĸ�����
		for(k=0;k<=3;k++)
		{
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			//�ж��Ƿ�Խ��
			if(tx<1||tx>n||ty<1||ty>n)
			 continue;
			//�ж��Ƿ����ϰ�������Ѿ���·����
			
			if(map[tx][ty]==0&&book[tx][ty]==0)
			{
				//���Ѿ�����Ľ����б��
				book[tx][ty]=1;
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].f=head;
				//�ý���Ǵ�head��չ�����ģ����Ա���丸��Ϊhead��������·�� 
				que[tail].s=que[head].s+1;//�����Ǹ��׵Ĳ���+1
				tail++;
				//����Ϊ��չ�Ľ�����Ӳ��� 				 
			 } 
			 //�ж��Ƿ��Ѿ��ﵽĿ�ĵ�
			 if(tx==p&&ty==q)
			 {
			 	flag=1;
			 	break;
			  } 
		}
		if(flag==1)
		 break;//˵���Ѿ��ҵ����������whileѭ��
		head++;//һ����չ���ҵ����丸�׳��Ӻ���ܽ�����һ����չ 
	 }	
	 //����Ϊȫ���������̣������ӡ�����Ľ��
	 i=que[tail-1].s;//tailָ����Ƕ�β�ĺ�һ��λ��,���һ��λ����tail-1
	 int top=0;//��ӡ·����ջ 
	 j=tail-1;//��Ŀ�Ľ�㿪ʼ��ջ 
	 for(k=0;k<=i;k++)
	 {
	 	stack[top++]=que[j];
	 	j=que[j].f;//ÿ��ָ���丸�� 
	 }
	 //��ӡ·��
	 while(top>=0)
	 {
	 	printf("Ŀ�ĵص�·��Ϊ:\n");
		printf("��%d,%d������>\n",stack[top].x,stack[top].y); 
		printf("�ܹ���Ҫ%d��",que[tail-1].s);
		top--; 
	  } 
	  return 0;
 }
