#include<stdio.h> 
int main()
{
	int e[10][10],dis[10],book[10],i,j,n,m,t1,t2,t3,u,v,min;
	int inf=99999999;//�����Ϊ�������
	//���붥���������
	scanf("%d %d",&n,&m);
	//��ʼ���洢����
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=inf; 
			
	//����ͼ����Ϣ
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&t1,&t2,&t3);
		e[t1][t2]=t3;
	}
	
	//��ʼ��dis���飬�˴�Ϊ����1�����������ĳ�ʼ·��
	for(i=1;i<=n;i++)
		dis[i]=e[1][i];
	
	//book�����ʼ������������Ѿ�ȷ���Ķ�����δȷ��·�̵Ķ���
	for(i=1;i<=n;i++)
		book[i]=0;
	
	book[1]=1;//��1�Ŷ��㿪ʼ�����ң���ʼ���1�Ŷ���
	//Dijsktra�㷨�������
	for(i=1;i<n;i++)//��ʣ�µ�n-1������������ȷ�����·��,��Ѱ��n-1�� 
	{
		//ÿ�ζ�Ѱ�ҵ���1������ĵ� 
		min=inf;
		for(j=1;j<=n;j++)
		{
			if(book[j]==0&&dis[j]<min)
			{
				min=dis[j];
				u=j;
			}
		 } 
		 book[u]=1;//�ҵ���1������ĵ������
		for(v=1;v<=n;v++)//����ĵ���Ϊ��1�Ŷ������ת�㣬����Ҫ��������dis�����ֵ 
		{
			if(e[u][v]<inf)
			{
				if(dis[v]>dis[u]+e[u][v])
					dis[v]=dis[u]+e[u][v];
			}
		}
	 } 
	for(i=1;i<=n;i++)
		printf("%d ",dis[i]);
	return 0;			 		 
}
