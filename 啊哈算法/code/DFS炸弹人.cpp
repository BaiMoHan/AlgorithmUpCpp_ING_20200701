#include<stdio.h>
int max,sum,p,q,m,n,book[50][50];
char map[50][50];
void deep_first_search(int x,int y);
int count(int x,int y);
int main()
{
	int i,j,startx,starty;
	//�����ͼ��Ϣ�Լ���ʼλ�� 
	scanf("%d %d %d %d",&m,&n,&startx,&starty);
	for(i=0;i<m;i++)
			scanf("%s",map[i]);
	book[startx][starty]=1;
	deep_first_search(startx,starty);
	printf("Ӧ�ý�ը������(%d,%d)��\n",p,q);
	printf("��ը��%d������",max);
	return 0; 
}
void deep_first_search(int x,int y)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	//�����������ϵ�ö��˳��
	int k,tx,ty;
	//ÿ�ο�ʼ��һ������֮ǰ��Ҫͳ�����е��ɱ���� 
	sum=count(x,y);
	if(sum>max)//�ж�ɱ����
	{
		p=x;
		q=y;//��¼���λ�õ����� 
		max=sum;//�������ֵ 
	 } 
	
	//��ʼ�����������ϵ�˳��������һ�����
	for(k=0;k<=3;k++)
	{
		tx=x+next[k][0];
		ty=y+next[k][1];
		//�ж��½���Ƿ�Խ��
		if(tx<0||ty<0||ty>m-1||ty>n-1)
			continue;
		//�жϽ���Ƿ��Ѿ�������	
		if(map[tx][ty]=='.'&&book[tx][ty]==0)
		{
			book[tx][ty]=1;//�����;
		 	deep_first_search(tx,ty);//��������������� 
		}	
	}
	return ;
}
int count(int x,int y)
{
	int k=0,tx,ty;
	//�������ΰ����������ϵ�˳��ͳ��ɱ����,ÿ��ͳ��Ҫ���ó�ʼ����
	tx=x;
	ty=y; 
	while(map[tx][ty]!='#')
	{
		if(map[tx][ty]=='G')
		{
			k++;
		}
		ty++;//����ͳ��,������ܷ�if���棬��Ϊ������һ��λ���ǿյ� 
	}
	
	tx=x;
	ty=y;
	while(map[tx][ty]!='#')
	{
		if(map[tx][ty]=='G')
		{
			k++;
		}
		tx++;//����ͳ�ƣ�������ܷ�if���棬��Ϊ������һ��λ���ǿյ� 
	 } 
	 
	 tx=x;
	 ty=y;
	 while(map[tx][ty]!='#')
	 {
	 	if(map[tx][ty]=='G')
	 	{
	 		k++;
		 }
		 ty--;//����ͳ�ƣ�������ܷ���if���棬��Ϊ��һ��λ�ÿ����ǿյ� 
	 }
	 
	 tx=x;
	 ty=y;
	 while(map[tx][ty]!='#')
	 {
	 	if(map[tx][ty]=='G')
	 	{
	 		k++;
		 }
		tx--;//����ͳ�ƣ�������ܷ���if���棬��Ϊ��һ��λ�ÿ����ǿյ� 
	 }
	 
	 return k;//���Ϊ��ɱ���� 
	} 

