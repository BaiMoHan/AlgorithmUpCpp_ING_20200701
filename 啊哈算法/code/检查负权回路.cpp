#include<stdio.h>
int main()
{
	int dis[10],i,k,n,m,u[10],v[10],w[10],bak[10],check,flag=0;
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
	{
		//ÿ���ɳڹ����������ݵ�bak�����У���������ж��Ƿ��ɳ� 
		for(i=1;i<=n;i++)
			bak[i]=dis[i]; 
		for(i=1;i<=m;i++)
			if(dis[v[i]]>dis[u[i]]+w[i])
				dis[v[i]]=dis[u[i]]+w[i];
		//�ɳ���Ϻ���dis�����Ƿ��и���
		 check=0;
		 for(i=1;i<=n;i++)
		{
			if(bak[i]!=dis[i])//˵������������ 
			{
				check=1;
				break;
			}
		}
		if(check==0)
			break;//˵��û�и��£������ɳ�Ҳ���˷�ʱ�䣬�˳�ѭ�� 
	}
	//��⸺Ȩ��·,������һ���ɳں�dis�����Ƿ�ı�
	for(i=1;i<=m;i++)
		if(dis[v[i]]>dis[u[i]]+w[i])
		{
			dis[v[i]]=dis[u[i]]+w[i];
			flag=1;
	}
	
	 //������յĽ��
	 if(flag==1) 
	 	printf("��ͼ���и�Ȩ��·");
	else
	  for(i=1;i<=n;i++)
	  	printf("%d ",dis[i]);
	
	return 0;
}
