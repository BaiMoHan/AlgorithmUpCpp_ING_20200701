#include<stdio.h>
struct node{
	int x;//��ź����� 
	int y;//��������� 
}que[100];//���ù�����������Ķ���
int BFS(int x,int y,int color);
int book[15][15],map[15][15],m,n;//����ȫ�ֱ��� 
int main() 
{
	int i,j,startx,starty;
	//�����ͼ��Ϣ����ʼλ��
	scanf("%d %d %d %d",&m,&n,&startx,&starty);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&map[i][j]); 
	i=BFS(startx,starty,-1);
	printf("����ĵ�������Ϊ:%d\n",i);
	//��ӡ�������
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%3d ",map[i][j]);//���ڴ�ӡ����������3d���
		//ע�⻻��
		printf("\n"); 
	 } 
	return 0;
}
int BFS(int x,int y,int color)
{
	int head=0,tail=0,k,tx,ty;
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	//�����������ϵ�˳�� 
	que[tail].x=x;
	que[tail].y=y;
	map[x][y]=color;//��ʼ��ɫ 
	tail++;//��ʼλ�����
	book[x][y]=1;//����Ѿ���ӵĽ�� 
	while(head<tail)//�����в�Ϊ��ʱ����ȱ���
	{
		for(k=0;k<4;k++)
		{
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			//�ж��Ƿ�Խ�� 
			if(tx<0||ty<0||tx>m-1||ty>n-1)
				continue;
			if(map[tx][ty]!=0&&book[tx][ty]==0)
			{
				book[tx][ty]=1;//����Ѿ��������Ľ��
				que[tail].x=tx;
				que[tail].y=ty;
				map[tx][ty]=color;//��ɫ���� 
				tail++;//��Ӳ���
			 } 
		}
		head++; 
	 }  
	return tail;//½����������ӵ���Ŀ 	
}
