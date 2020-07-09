#include<stdio.h>
int dis[7],book[7],h[7],pos[7],size;
//dis存放生成树与其他顶点的距离，book标记已是树的顶点
//h用来保存堆，pos用来存储每个顶点在堆中的位置，size为堆的大小
void swap(int x,int y);//交换堆中结点x与结点y的值
void siftdown(int i);//从结点i开始向下调整堆
void siftup(int i);//从结点i开始向上调整堆
int pop();//从堆顶取出一个元素
int main()
{
	int n,m,i,j,k;
	//u,v,w,next数组根据实际情况来设置构建邻接表，此图是无向图,要比2*m大1
	//first要比n的值大1，比2*m的值大1
	int u[19],v[19],w[19],first[7],next[19];
	int inf=99999999;//此处用99999999代表正无穷
	int count=0,sum=0;//count用来记录生成树中顶点的个数,sum用来存储路径之和
	//读入顶点个数和边数
	scanf("%d %d",&n,&m);
	//开始读入边
	for(i=1;i<=m;i++)
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		
	//此处是无向图，还需要把所有的边方向存储一次
	for(i=m+1;i<=2*m;i++)
	{
		u[i]=v[i-m];
		v[i]=u[i-m];
		w[i]=w[i-m];
	 } 
	 //开始用邻接表存储边
	 for(i=1;i<=n;i++)
	 	first[i]=-1;
	 	
	 for(i=1;i<=2*m;i++)
	 {
	 	next[i]=first[u[i]];
	 	first[u[i]]=i;
	 }
	 //prim算法核心部分
	 //将1号顶点加入生成树中
	 book[1]=1;//加入树的顶点进行标记
	 count++;//记录已经成为生成树的顶点
	 //初始化dis数组，最开始是1号顶点到其余各个顶点的初始距离
	 dis[1]=0;
	 for(i=2;i<=n;i++)//因为1号顶点已经加入，所以从i=2开始
	 	dis[i]=inf;
	//从邻接表中取出1号顶点的各边 
	 k=first[1]; 
	//遍历1号顶点的所有边
	while(k!=-1)
	{
		dis[v[k]]=w[k];
		k=next[k];
	 } 
	 //初始化堆
	 size=n;
	 for(i=1;i<=size;i++)
	 {
	 	h[i]=i;
	 	pos[i]=i;
	  } 
	 for(i=size/2;i>=1;i--)
	 	siftdown(i);//从子树开始向下调整
	 pop();//先弹出一个堆顶元素，此时堆顶为1号顶点
	 while(count<n)
	 {
	 	j=pop();
	 	book[j]=1;//选出堆中最近的顶点标记上
		count++;
		sum=sum+dis[j];//更新最小生成树的权值
		//由于加入了j顶点，其他顶点与新的生成树的最短距离会发生改变
		//扫描与顶点j相关的所有边，看能否让顶点j成为中转点
		k=first[j];
		while(k!=-1)
		{
			if(0==book[v[k]] && dis[v[k]]>w[k])
			{
				dis[v[k]]=w[k];//更新距离
				siftup(pos[v[k]]);//对该点在堆中进行向上调整 
				//注意pos[[v[k]]存储的是该点在堆中的位置 
			}
			k=next[k];
		 } 
	  } 
	 printf("最小生成树的权值为%d",sum);
	  return 0;
 } 
 void swap(int x,int y)
 {
 	//交换堆中元素x与元素y的值 
 	int t;
 	t=h[x];
 	h[x]=h[y];
 	h[y]=t;
 	//注意到pos数组是存放顶点在堆中的位置，当交换堆中两元素，也要改变pos数组
	t=pos[h[x]];
	pos[h[x]]=pos[h[y]];
	pos[h[y]]=t; 
 }
 void siftdown(int i)//从堆中结点i开始向下调整,此处建立最小堆
 {
 	int t,flag=0;//flag用来标记上是否已经处于合适的位置 
 	while(2*i<=size && 0==flag)
 	{
 		//能进入循环，则说明左儿子一定存在，先与左儿子比较
		if(dis[h[i]]>dis[h[i*2]])
			t=i*2;
		else
			t=i;
		//判断是否存在右儿子
		if(i*2+1<=size)
		{
			if(dis[h[t]]>dis[h[2*i+1]])//与右儿子比较 
				t=2*i+1;
		 } 
		 if(i!=t)//判断此轮是否需要进行交换 
		 {
		 	swap(i,t);
		 	i=t;
		 }
		 else
		 	flag=1;//不需要交换则说明已经处于合适的根结点处 
	 }
  } 
  void siftup(int i)//从结点i开始向上调整
  {
  	int flag=0;//用来标记是否需要继续向上调整
	//先判断当前元素是否处于堆顶
	if(1==i)
		return ;
	while(i!=1 && 0==flag)
	{
		//判断是否比父亲小
		if(dis[h[i]]<dis[h[i/2]])
			swap(i,i/2);//交换它与爸爸的值
		else
			flag=1;//说明不出要再向上调整了
		i=i/2; 
	 } 
   } 
 int pop()
 {
 	//从取出堆顶元素 
 	int t;
 	t=h[1];//临时变量记录堆顶的值
	pos[t]=0;//取出后，不在堆中，所以改变pos数组中的值
	h[1]=h[size];//把堆的最后一个值赋给对堆顶
	pos[h[1]]=1;//元素在堆中改变位置后，pos的值也会发生变化 
	size--;//元素个数减少
	siftdown(1);//从堆顶向下调整
	return t;//返回记录的堆顶值 
 }
