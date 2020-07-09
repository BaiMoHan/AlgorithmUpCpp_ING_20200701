#include<stdio.h>
int map[15][15],book[15][15],m,n,sum=1;
void DFS(int x,int y,int color);
int main()
{
	int i,j,startx,starty;
	//�����ʼ��Ϣ
	scanf("%d %d %d %d",&m,&n,&startx,&starty);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&map[i][j]);
	book[startx][starty]=1;//��ʼλ�ñ��Ϊ1
	DFS(startx,starty,-1);
	printf("��������Ϊ%d\n",sum);
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
void DFS(int x,int y,int color)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	//�����������ϵ�˳��
	map[x][y]=color;//��ɫ 
	int k,tx,ty;
	for(k=0;k<4;k++)
	{
		tx=x+next[k][0];
		ty=y+next[k][1];
		//�ж��Ƿ�Խ�� 
		if(tx<0||ty<0||tx>m-1||ty>n-1)
			continue;
		if(map[tx][ty]!=0&&book[tx][ty]==0)
		{
			book[tx][ty]=1;//�����
			sum++;//ͳ��½����� 
		 	DFS(tx,ty,-1);//�������������������һ����� 
		}
	}
	return ; 
}
