//PAT_B1036_跟奥巴马一起编程
#include<cstdio>
int main()
{
	int row,col,k;//行，列
	char c;
	//读入列数和打印的字符
	scanf("%d %c",&col,&c);
	//根据列数的奇偶性判断打印的行数
	if(col%2)
		//如果是奇数列
		row=col/2+1;
	else
		row=col/2; 
	//开始打印图形，第一行所有列都打印
	for(int i=1;i<=col;i++)
		printf("%c",c);
	printf("\n\n");
	for(k=2;k<row;k++)
	{
		printf("%c",c);//先打印出首字符c
		for(int i=0;i<col-2;i++)//打印col-2个空格
			printf(" ");
		printf("%c\n",c);//末尾打印一个空格 
		printf("\n");//中间空一行 
	 } 
	 //最后一行全部打印
	 for(int i=1;i<=col;i++)
	 	printf("%c",c); 
 } 
