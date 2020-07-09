#include<stdio.h>
int f[1000],n,m,k,sum;//c语言全局变量默认值初始为0
void init();//初始化并查集的数组函数
int find(int v);//递归找根的函数
void merge(int v,int u);//合并两个子集的函数 
int main()
{
	int i,x,y;
	scanf("%d %d",&n,&m);
	//初始化数组
	init();
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);//读取结点之间的信息
		merge(x,y);//每读取一条，合并一次 
	 } 
	 //合并完之后，扫描有多少个根结点
	 for(i=1;i<=n;i++)
	 {
	 	if(f[i]==i)//根结点指向自身
	 		sum++;
	  } 
	  printf("独立团伙个数为%d",sum);
	  return 0;
 } 
 void init()
 {
 	//初始化并查集的数组
	 int i;
	 for(i=1;i<=n;i++)
	 	f[i]=i;//一开始每一个元素都指向自己 
 }
 int find(int v)
 {
 	//找出v的根结点 
	 if(v==f[v])
	 	return v;//根结点指向的是自己
	else
	{
		//递归调用 
		f[v]=find(f[v]);//只要求找到根结点，此处相当于改变了原来的树，压缩了路径 
		return f[v];//返回根结点 
	 } 
 }
 void merge(int v,int u)
 {
 	int t1,t2;//存放两个集合的根结点 
 	t1=find(v);//找到v的根结点 
 	t2=find(u);//找到u的根结点 
	if(t1!=t2)//判断两个根结点是否相同从而判断是否在同一个集合中
	{
		//此处采用有秩合并原则，即把右边的集合作为左边集合的子集合 
		f[t2]=t1; 
	 } 
 }
  
