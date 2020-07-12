//求APPAPT中包含了多少个PAT单词
#include<cstdio>
#include<cstring>
const int MAXN=10010; //字符串的最大长度
const int MOD=100000007;	//为避免总结果太大，最后求模
char str[MAXN];		//设置字符串数组
int leftNumP[MAXN]={0};	//初始化字母A的左边P字母的个数存放数组 
int main()
{
	scanf("%s",str);	//读入字符串
	int len=strlen(str);//求该字符串的长度
	int i;		//设置循环变量
	for(i=0;i<len;i++)	//更新leftNumP数组,即该字符左边P字母的个数
	{
		if(str[i]=='P')	//当前字符为P
			leftNumP[i]=leftNumP[i-1]+1;//在前一位的基础上增加1
		else		//当前字符不是P
			leftNumP[i]=leftNumP[i-1];	//P的个数与前一位的相同 
	 } 
	 int ans=0,rightNumT=0;	//总PAT个数,字符右边T的个数 
	for(i=len-1;i>=0;i--)	//从末尾往前推统计T的个数,并找字符A 
	{
		if(str[i]=='T')	//当前字符为T
			rightNumT++;//当前T的字符自增
		else if(str[i]=='A')//当前字符为A
			ans+=(leftNumP[i]*rightNumT)%MOD;	//累加个数 
	}
	printf("个数为%d",ans);	//输出结果
	return 0; 
}







