#include<stdio.h>
int n,m,e[9][9],root;
int num[9],low[9],flag[9],index;//index��������ʱ����ĵ���
int min(int a,int b);//���a��b����������С��һ��
void dfs(int cur,int father);//������㷨�����������������
int main()
{
	int i,j,x,y;
	//���붥�����ͱ��� 
	scanf("%d %d",&n,&m);
	//��ʼ��ͼ�Ĵ洢��ά���� 
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			e[i][j]=0;
	
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		e[x][y]=1;
		e[y][x]=1;
	}
	root=1;
	dfs(1,root);//��1�Ŷ��㿪ʼ������ȱ���
	for(i=1;i<=n;i++)
	{
		if(1==flag[i])
			printf("���Ϊ%d�Ŷ���",i);
	 } 
	 return 0;
 } 
 int min(int x,int y)
 {
 	return x < y ? x : y ;
 }
 void dfs(int cur,int father)
 //��������������ֱ�Ϊ��ǰ�����ź͸�����ı�� 
 {
 	int child=0,i,j;//child������¼���������е�ǰ����cur�Ķ��Ӹ���
	index++;//ʱ�����1
	num[cur]=index;//��ǰ����cur��ʱ���
	low[cur]=index;//��ǰ�����ܷ��ʵ����綥���ʱ������ʼ�Ƿ����Լ�
	for(i=1;i<=n;i++)//ö���뵱ǰ����cur�б������Ķ���i
	{
		if(1==e[cur][i])//�ж���������Ƿ��б� 
		{
			if(0==num[i])//�������i��ʱ���Ϊ0����˵������i��û�б����ʹ�
			{
				child++;
				dfs(i,cur);//�������������������
				//���µ�ǰ����cur�ܷ��ʵ����綥���ʱ���
				low[cur]=min(low[cur],low[i]);
				//�����ǰ���㲻�Ǹ���㲢������low[i]>=num[cur],��ǰ����Ϊ���
				if(cur!=root && low[i]>=num[cur])
					flag[cur]=1;
				//�����ǰ�����Ǹ���㣬���������и�������Ҫ���������ӣ���ô����������Ǹ��
				if(cur==root && 2==child)
					flag[cur]=1; 
			 } 
			 else if(i!=father)
			 //�����������i���������ʹ�������������㲻�ǵ�ǰ����cur�ĸ��ף�����Ҫ���µ�ǰ���cur�ܷ���ʵ����綥���ʱ���
			 {
			 	low[cur]=min(low[cur],num[i]);
			  } 
		}
	 } 
 }
