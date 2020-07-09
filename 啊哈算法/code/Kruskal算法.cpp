#include<stdio.h>
struct edge
{
	//����u������v��ȨֵΪw 
	int u; 
	int v;
	int w;
}e[10];//Ϊ�˷������򣬴���һ���ṹ�����洢�ߵĹ�ϵ 
int n,m,f[7],sum,count;//�������鼯����Ҫ��һЩ������C����ȫ�ֱ���Ĭ�ϳ�ʼΪ0
//f����Ĵ�СҪ����ʵ������������Ҫ��n��һ
void quicksort(int left,int right);//���ÿ�������������ߵ�Ȩֵ
int find(int v);//���鼯�Ҹ���㺯��
int merge(int v,int u);//�ϲ�u��v�������ϵĺ���
int main()
{
	int i;
	//��ȡ�������ͱ��� 
	scanf("%d %d",&n,&m);
	//����ߵ���Ϣ,ע��˴��ǽṹ��洢
	for(i=1;i<=m;i++)
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	//ʹ�ÿ��ţ�����С�������� 
	quicksort(1,m);
	//���鼯��ʼ��
	for(i=1;i<=n;i++)
		f[i]=i;
	//kruskal�㷨���Ĳ���
	for(i=1;i<=m;i++)
	{
		//�����ж�һ���ߵ����������Ƿ��Ѿ���ͨ
		if(merge(e[i].u,e[i].v))
		{
			count++;
			sum=sum+e[i].w;
		 } 
		 if(count==n-1)//ѡ����n-1���ߺ���ζ����С�������������
		 	break; 
	 } 
	 printf("��С��������ȨֵΪ%d",sum);
	 return 0;
 } 
 void quicksort(int left,int right)
 {
 	int i,j;
 	struct edge temp;//����Ԫ��ʱ�õ���ʱ�洢 
 	if(left>right)
 		return ;
 	
 	i=left;
 	j=right;
 	while(i!=j)
	{
		//˳�����Ҫ���ȴ��ұ߿�ʼ��
		while(e[j].w>=e[left].w && i<j)
			j--;
		//�ٴ���߿�ʼ��
		while(e[i].w<=e[left].w && i<j)
			i++;
		//����
		if(i<j)
		{
			temp=e[i];
			e[i]=e[j];
			e[j]=temp;
		 } 
	}
	//���ս���׼����λ����left��i����
	temp=e[left];
	e[left]=e[i];
	e[i]=temp;
	
	quicksort(left,i-1);//�ݹ���ô�����ߵ�
	quicksort(i+1,right);//�ݹ���ô����ұߵ�
	return ; 
  } 
  int find(int v)
  {
  	if(f[v]==v)
  		return v;
  	else
  	{
  		f[v]=find(f[v]);//·��ѹ��
		return f[v]; 
	  }
  }
int merge(int v,int u)
{
	int t1,t2;
	t1=find(v);//�ҵ����v�����ĸ���� 
	t2=find(u);//�ҵ����u�����ĸ���� 
	if(t1!=t2)
	{
		f[t2]=t1;//���Ⱥϲ�������ԭ��
		return 1; 
	}
	return 0;
}
