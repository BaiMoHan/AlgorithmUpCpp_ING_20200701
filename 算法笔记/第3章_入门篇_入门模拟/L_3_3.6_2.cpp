//PAT_B1009说反话 
#include<cstdio>
#include<cstring>
int main()
{
	char str[90];
	int i;//总长度不超过80
	while(gets(str)!=NULL)
	{
		for(i=0;str[i]!='\0';i++);//遍历到字符串末尾
		//逆向输出 
		for(i=i-1;i>=0;i--)
			printf("%c",str[i]);
		//输出完毕后输出一个换行
		printf("\n"); 
	 } 
	 return 0;
}
