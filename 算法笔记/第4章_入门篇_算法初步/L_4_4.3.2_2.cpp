//回溯法求n皇后问题,把n列皇后所在的行数写成一串，就构成一个排列数
#include<stdio.h>
#include<math.h>
const int maxn=11;
bool flag;//回溯过程中的标记 
int n,P[maxn],hashTable[maxn]={false},count;
//P存放排列，hashTable用来标记数是否已经放过,count计数皇后的放法个数 
void generateP(int index);
int main()
{
	scanf("%d",&n);//读入皇后的个数
	generateP(1);//从1开始找生产排列
	return 0; 
 } 
 void generateP(int index)
 {
 	if(index==n+1)//能到达这里的说明都是符合要求的
	 {
	 	count++;//摆放个数自增
		for(int i=1;i<=n;i++)//打印摆放方式 
			printf("%d",P[i]);
		printf("\n这是第%d种摆放方式\n",count);
		return ;
	  } 
	//找排列从1-n的顺序枚举，中间注意控制皇后判定条件
	for(int x=1;x<=n;x++)//考虑第index列的皇后放在第x行是否可行 
	{
		if(hashTable[x]==false)
		{
		//说明第x行还没有皇后
			flag=true;//说明此行要放一个皇后 
		//下面考虑此行的皇后与规则冲突的，即考虑前面的1~x-1行的皇后
			for(int pre=1;pre<index;pre++)//遍历之前的皇后
			{
		//第index列的皇后的行号为x，第pre列皇后的行号为P[pre]
				if(abs(index-pre)==abs(x-P[pre]))//判定是否两皇后在对角线上
				{
					flag=false;//说明放在x处不行
					break;//跳出循环 
				 } 
		 	} 
			 if(flag)//flag为真，即说明可以把index列的皇后放在x行处
			 {
		 		P[index]=x;//把第index列的皇后放在第x行
				hashTable[x]=true;//第x行不可再放置皇后
				generateP(index+1);//递归处理第index+1列的皇后应该放置的行号
				hashTable[x]=false;//每一次递归完毕之后必须复原标记，才可以开始下一次尝试 
		  	}
		}
	 } 
 }
 
 
 
 
 
 
 
 
 
