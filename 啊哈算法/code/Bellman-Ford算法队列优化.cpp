#include<stdio.h>
int main()
{
	int n,m,i,j,k;
	//u,v,w�������СҪ����ʵ����������ã�Ҫ�ȱ���m�����ֵ��1
	int u[8],v[8],w[8];
	
	//firstҪ��n�����ֵ��1��nextҪ��m�����ֵ��1
	int first[6],next[8];
	
	int dis[6]={0},book[6]={0};
	//book�������������Щ�����Ѿ��ڶ����У��˴�����ʱ�Ѿ���ʼ�� 
	
	int que[101]={0},head=1,tail=1;//����һ�����У�����ʼ������
	int inf=99999999;//�˴����������
	
	//��������Ͷ�����
	scanf("%d %d",&n,&m);
	//��ʼ��dis���飬Ϊ1�Ŷ��㵽��������ĳ�ʼ����
	
	for(i=2;i<=n;i++)
	//����ʱ���Ѿ���ʼ��dis����Ϊ0,1�Ŷ��㵽����Ϊ0,��˴�2�Ŷ��㿪ʼ��ʼ�� 
		dis[i]=inf;
		
	//��ʼ��first���飬-1��ʾ1~n���㶼��ʱû�б�
	for(i=1;i<=n;i++)
		first[i]=-1;
	//����ߵ���Ϣ�������ڽӱ�
	for(i=1;i<=m;i++)
	{
		//�Ӷ���u[i]������v[i]��ȨֵΪw[i] 
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		next[i]=first[u[i]];
		first[u[i]]=i;
	 } 
	 
	 //1�Ŷ������
	 que[tail]=1;
	 tail++;
	 book[1]=1;//���1�Ŷ����Ѿ����
	 while(head<tail)//���в�Ϊ��ʱѭ��
	{
		k=first[que[head]];//��ǰ��Ҫ����Ķ��׶���
		while(k!=-1)//������ǰ��������б�
		{
			//�ж��Ƿ��ɳ�
			if(dis[v[k]]>dis[u[k]]+w[k])
			{
				dis[v[k]]=dis[u[k]]+w[k];
				//���濼�Ǹö����Ƿ��Ѿ��ڶ�����
				if(0==book[v[k]])
				{
					que[tail]=v[k];
					tail++;//��Ӳ��� 
					book[v[k]]=1; //���֮���� 
				 }
			 }
			 k=next[k];
		 } 
		 //���� 
		 book[que[head]]=0;
		 head++;
	}
	//��ӡ���·��
	for(i=1;i<=n;i++)
		printf("%d ",dis[i]);
	
	return 0; 
	
}
