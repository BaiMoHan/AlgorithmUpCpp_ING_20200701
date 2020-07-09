#include<stdio.h>
int map[15][15],book[15][15],m,n,num=-1;
void DFS(int x,int y,int color);
int main()
{
	int i,j,sum=0;
	//�����ʼ��Ϣ
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&map[i][j]);
	//��ÿһ�������dfs 
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(map[i][j]>0)
			{
				DFS(i,j,num);
				sum++;
				num--;
			}
		}
	}
	//��ӡ�������
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%3d ",map[i][j]);//���ڴ�ӡ����������3d���
		//ע�⻻��
		printf("\n"); 
	 }  
	 printf("���й���С������%d",sum) ; 
	return 0;
}
void DFS(int x,int y,int color)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	//�����������ϵ�˳��
	map[x][y]=color;//��ɫ 
	book[x][y]=1;//��ʼ����� 
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
		 	DFS(tx,ty,num);//�������������������һ����� 
		}
	}
	return ; 
}
