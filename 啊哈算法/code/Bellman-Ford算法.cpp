#include<stdio.h>
int main()
{
	int dis[10],i,k,n,m,u[10],v[10],w[10];
	int inf=99999999;//�˴�����������
	//���붥���������
	scanf("%d %d",&n,&m);
	
	//�����,����u[i]��v[i]��ȨֵΪw[i] 
	for(i=1;i<=m;i++)
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		
	//��ʼ��dis���飬������1�Ŷ��㵽�����������ĳ�ʼ·��
	for(i=1;i<=n;i++)
		dis[i]=inf;
	dis[1]=0;//1�Ŷ��㵽����Ϊ0
	
	//Bellman-Ford�㷨������� 
	for(k=1;k<n;k++)//�˴�ѭ��n-1�֣���Ϊn������֮�����n-1����
		for(i=1;i<=m;i++)
			if(dis[v[i]]>dis[u[i]]+w[i])
				dis[v[i]]=dis[u[i]]+w[i];
	 //������յĽ��
	  for(i=1;i<=n;i++)
	  	printf("%d ",dis[i]);
	
	return 0;
}
