//给出N个字符串（由恰好三位大写字母组成），再给出M个查询字符串，
//问每个查询字符串在N个字符串中出现的次数
#include<stdio.h>
const int maxn=100;
char S[maxn][5],temp[5];
int hashTable[26*26*26+10];
int hashFunc(char S[],int len);//hash函数，将字符串转换为整数 
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);//n个字符串，m个查询串
	for(int i=0;i<n;i++)//读入n个串
	{
		scanf("%s",S[i]);
		int id=hashFunc(S[i],3);//将字符串转换为整数
		hashTable[id]++; //该字符串出现的次数+1 
	 } 
	 for(int i=0;i<m;i++)
	 {
	 	scanf("%s",temp);//读取查询串
		int id=hashFunc(temp,3);//将字符串temp转换为整数
		printf("%d\n",hashTable[id]); 
	 }
 } 
 int hashFunc(char s[],int len)
 {
 	int id=0;
 	for(int i=0;i<len;i++)
 		id=id*26+(s[i]-'A');//将26进制转换为十进制
	return id; 
  } 
