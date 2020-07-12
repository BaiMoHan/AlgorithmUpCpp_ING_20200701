//用递归来解决全排列问题
#include<cstdio>
const int maxn=11;//因为有0-9这十个数 
int n,P[maxn],hashTable[maxn]={false};//P为当前排列，hashTable记录整数x是否已经在P中
void generateP(int index);
int main()
{
	n=5;//输出3的全排列 
	generateP(1);//从1开始试探 
	return 0;
}
void generateP(int index)
{
	if(index==n+1)//递归边界，说明1-n位已经排好
	{
		//输出已经排好的序列
		for(int i=1;i<=n;i++)
			printf("%d",P[i]);
		//序列输出完整后打印一个空格 
		printf("\n"); 
		return ;//递归结束 
	 } 
	 for(int x=1;x<=n;x++)//枚举1-n，试图将x填入P[index]
	 {
	 	if(hashTable[x]==false)//说明x不在P中，可以填入
		 {
		 	P[index]=x;//把x加入当前排列
			hashTable[x]=true;//标记x已经在P中
			generateP(index+1);//处理下一号位的数字
			hashTable[x]=false;//已经处理完P[index]的子问题，还原状态，才可进行下一次尝试 
		  } 
	  } 
	 
 } 
