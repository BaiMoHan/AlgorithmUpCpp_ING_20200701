#include<stdio.h>
int n,m,p,q,min=9999999,a[51][51],book[51][51];
void deep_first_search(int x,int y,int step);
int main()
{
	int i,j,startx,starty;
	//�����ͼ״��
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
			
	//�����ʼ������Ŀ������ 
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	book[startx][starty]=1;//��ʼλ���Ѿ���·������ 
	deep_first_search(startx,starty,0);
	
	printf("�����Ҫ%d��",min); 
	return 0;
	
 } 
void deep_first_search(int x,int y,int step)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	//���������������ϵ�˳��ÿ���е�һ���仯����x���꣬�ڶ�����y���� 
	
	int tx,ty,k;
	if(x==p&&y==q)
	{
		//˵���Ѿ�������С����λ�ã������ж��Ƿ�����С����
		if(step<min)
		{
			min=step;
		 } 
		 return ;//�������Ҫ���� 
	 } 
	 
	 //�����������ϵ�˳������ö�� 
	 for(k=0;k<4;k++)
	 {
	 	//������һ���������
		 tx=x+next[k][0];
		 ty=y+next[k][1];
		 
		 //�ж���һ���Ƿ�Խ��
		 if(tx<1||tx>n||ty<1||ty>n)
		 	continue;
			 
		 //�ж���һ���Ƿ�Ϊ�ϰ�������Ѿ���·���� 
		 if(a[tx][ty]==0&&book[tx][ty]==0)
		 {
		 	book[tx][ty]=1;//�����
			deep_first_search(tx,ty,step+1);//��һ��Ҳ��ͬ���ݹ���� 
			
			book[tx][ty]=0;//����֮��Ҫȡ����ǣ���ʼ��һ�α�� 
		  } 		  
	  } 
	  return ;
}
