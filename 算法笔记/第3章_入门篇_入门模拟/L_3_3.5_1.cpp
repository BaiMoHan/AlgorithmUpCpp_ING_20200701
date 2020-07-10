//PAT_B1022_D进制的A+B
#include<cstdio>
int main()
{
	unsigned int a,b,d;
	scanf("%d %d %d",&a,&b,&d);
	unsigned int c=a+b;
	//对C转换为d进制
	int ans[31],num=0;
	//ans存放进制的每一位，由于该数字位数最多按二进制可放30位
	//进制转换
	do{
		ans[num++]=c%d;
		c/=d;
	} while(c);
	//按高位到低位输出
	for(int i=num-1;i>=0;i--)
		printf("%d",ans[i]);
	return 0; 
	 
 } 
