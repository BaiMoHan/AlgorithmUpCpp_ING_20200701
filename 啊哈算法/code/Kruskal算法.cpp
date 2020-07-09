#include<stdio.h>
struct edge
{
	//顶点u到顶点v的权值为w 
	int u; 
	int v;
	int w;
}e[10];//为了方便排序，创建一个结构体来存储边的关系 
int n,m,f[7],sum,count;//声明并查集所需要的一些变量，C语言全局变量默认初始为0
//f数组的大小要根据实际来定，至少要比n大一
void quicksort(int left,int right);//采用快速排序来排序边的权值
int find(int v);//并查集找根结点函数
int merge(int v,int u);//合并u和v两个集合的函数
int main()
{
	int i;
	//读取顶点数和边数 
	scanf("%d %d",&n,&m);
	//读入边的信息,注意此处是结构体存储
	for(i=1;i<=m;i++)
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	//使用快排，按从小到大排序 
	quicksort(1,m);
	//并查集初始化
	for(i=1;i<=n;i++)
		f[i]=i;
	//kruskal算法核心部分
	for(i=1;i<=m;i++)
	{
		//首先判断一条边的两个顶点是否已经连通
		if(merge(e[i].u,e[i].v))
		{
			count++;
			sum=sum+e[i].w;
		 } 
		 if(count==n-1)//选入了n-1条边后意味着最小生成树构建完成
		 	break; 
	 } 
	 printf("最小生成树的权值为%d",sum);
	 return 0;
 } 
 void quicksort(int left,int right)
 {
 	int i,j;
 	struct edge temp;//交换元素时用的临时存储 
 	if(left>right)
 		return ;
 	
 	i=left;
 	j=right;
 	while(i!=j)
	{
		//顺序很重要，先从右边开始找
		while(e[j].w>=e[left].w && i<j)
			j--;
		//再从左边开始找
		while(e[i].w<=e[left].w && i<j)
			i++;
		//交换
		if(i<j)
		{
			temp=e[i];
			e[i]=e[j];
			e[j]=temp;
		 } 
	}
	//最终将基准数归位，将left与i互换
	temp=e[left];
	e[left]=e[i];
	e[i]=temp;
	
	quicksort(left,i-1);//递归调用处理左边的
	quicksort(i+1,right);//递归调用处理右边的
	return ; 
  } 
  int find(int v)
  {
  	if(f[v]==v)
  		return v;
  	else
  	{
  		f[v]=find(f[v]);//路径压缩
		return f[v]; 
	  }
  }
int merge(int v,int u)
{
	int t1,t2;
	t1=find(v);//找到结点v所属的根结点 
	t2=find(u);//找到结点u所属的根结点 
	if(t1!=t2)
	{
		f[t2]=t1;//按秩合并，靠左原则
		return 1; 
	}
	return 0;
}
