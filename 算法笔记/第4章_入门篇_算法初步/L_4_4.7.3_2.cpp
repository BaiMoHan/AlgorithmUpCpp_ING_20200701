//将一个整数集合划分为两个子集,要求元素个数之差绝对值最小,各集合元素和之差的绝对值最小
//用到随机选择算法，前K大的元素放一个子集，剩下的放到另一个子集
//比快排要快，期望为线性阶时间复杂度
#include<cstdio>
#include<cstdlib>
#include<math.h>//用到只保留整数部分的函数round
#include<ctime> //利用时间来初始化随机数种子
#include<algorithm>	//STL算法
using namespace std;
const int maxn=10010;//集合的总元素最大数目 
int A[maxn],n;	//A数组存放所有整数，n为元素的个数
int randPartition(int A[],int left,int right);	//随机选择主元划分函数
void randSelect(int A[],int left,int right,int K);//随机选择第K大的算法函数
int main()
{
	srand((unsigned) time(NULL));//初始化随机数种子
	int sum=0,sum1=0;//sum为总元素之和,sum1为切分后前n/2个元素之和
	scanf("%d",&n);		//读取总元素的个数
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);//将元素依次读入到数组中
		sum+=A[i];	//累加求元素和 
	 } 
	randSelect(A,0,n,n/2);	//找第n/2大的元素,进行划分
	for(int i=0;i<n/2;i++)	//求出前n/2的累加和,即划分后其中一个子集的元素和
		sum1+=A[i];			//元素依次累加
	printf("两集合的元素之差为%d",sum-(sum-sum1));
	return 0; 
 } 
int randPartition(int A[],int left,int right)
{
	//生成[left,right]之间的随机数p
	int p=(round(1.0*rand()/RAND_MAX*(right-left)+left));
	swap(A[p],A[left]);	//将A[p]与A[left]交换,swap函数在<algorithm>库里面
	//以下为原先选定a[left]为主元的函数Paritition代码
	int temp=A[left];	//将A[left]存放至临时变量中
	while(left<right)	//当left比right小的时候就开始交换比较元素
	{
		//先从远离空房子的一边进行指针的移动操作 
		while(left<right && A[right]>temp)	//两指针未相遇且右指针大于temp
			right--;		//右指针自减
		A[left]=A[right];	//将A[right]的值放至空房子A[left]
		while(left<right && A[left]<=temp)	//两指针未相遇且左指针小于等于temp
			left++;			//左指针自增
		A[right]=A[left];	//将A[left]放置空房子 
	 } 
	 A[left]=temp;		//两指针相遇时即为存放temp的空房子
	 return left;		//返回temp的位置作为temp两侧递归的必要参数 
}
void randSelect(int A[],int left,int right,int K)
{
	if(left==right)	return ;	//边界
	int p=randPartition(A,left,right);	//确定划分后的主元位置
	int M=p-left+1;		//A[p]是A中的第M大 
	if(K==M)	return	;		//划分后p恰好是第K大
	if(K<M)		//第K大的数在主元左侧
		randSelect(A,left,p-1,K);	//在主元左侧找第K大
	else 		//第K大的数在主元右侧
		randSelect(A,p+1,right,K-M);		//在主元右侧找第K-M大  
}
 
