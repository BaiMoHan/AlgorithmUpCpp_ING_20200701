#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
char str[300];
char temp[300];
struct Node{
	int kind;//四个字节,0x1f1f1f1f
	//4节代表是否是选项,3字节代表有参数,2字节高4位代表是否出现在字符串,剩下的12位代表参数位置 
}node[30];//node[i]的字符是i+'a',节省空间，全局变量初始为0 

void freshNode()//更新结构体 
{
	_rep(i,0,26)
	{
		//去掉低16位 
		node[i].kind&=0xffff0000;
	}
}
bool judgeTemp()
{
	if(strlen(temp)==0)
		return false;
	if(strlen(temp)==1)
		return true;
	else if(temp[0]!='-')
		return true;
	else if(temp[1]<='z'&&temp[1]>='a'&&((node[temp[1]-'a'].kind&0x1f000000)!=0x1f000000))
		//是命令行选项
		return true; 
	else
		return false;
}
void readLine(char *str)//读取一行 
{
	char ch;
	_rep(j,0,300)
	{
		ch=getchar();
		if(ch=='\n')
		{ 
			str[j]='\0'; 
			break;
		} 
		str[j]=ch;
	}
}
int readWord(char* temp,int num)//读取一个单词
{
	_rep(i,0,300)
	{
		if(str[num+i]=='\0'||str[num+i]==' ')
		{
			temp[i]=str[num+i];
			return i;
		}else{
			temp[i]=str[num+i];
		}
	 } 
 } 
 
int main()
{
	#ifndef OJ
	freopen("201403-3.txt","r",stdin);
	#endif
	

	//读取命令选项
	readLine(str);
	int len=strlen(str); 
	_rep(i,0,len)
	{
		if(str[i]==':')
		{
			//标记带参数 
			node[str[i-1]-'a'].kind|=0x001f0000;
		}else{
			//标记是选项
			node[str[i]-'a'].kind|=0x1f000000; 
		}
	}
		

	int n,cnt,t;	//命令条数,计数器 
	bool ex=false; 
	cin>>n;
	getchar();//过滤换行
	
	 
	_rep(i,0,n)
	{
		readLine(str); 
		len=strlen(str);//获取命令字符串长度 
		//过滤前面的固有命令 
		cnt=0;
		while(str[cnt]!=' '&&str[cnt]!='\0')
			//找到第一个空格
			cnt++;
		
		cnt++; 
		while(cnt<len)
		{
			
			t=readWord(temp,cnt);
			if(t==2&&str[cnt]=='-')
			{
				//判断是不是命令 
				if(str[cnt+1]<='z'&&str[cnt+1]>='a')//说明可能是命令选项 
				{
					if((node[str[cnt+1]-'a'].kind&0x1f000000)==0x1f000000)
					{
						//是命令选项，表示出现在字符串中
						node[str[cnt+1]-'a'].kind|=0x0000f000;
						//进一步判断是否有参数
						if((node[str[cnt+1]-'a'].kind&0x001f0000)==0x001f0000)
						{
							//有参数的选项
							cnt+=t;
							cnt++;
							t=readWord(temp,cnt);
							if(judgeTemp())
							{
								//标记该参数的位置
								node[str[cnt-2]-'a'].kind&=0xfffff000;//先清空上一次的位置 
								node[str[cnt-2]-'a'].kind|=cnt;
								cnt+=t;
								cnt++;
							}
						 }else
						 {
						 	//无参数 继续下一轮
						 	cnt+=t;
							cnt++; 
							 
						 }
					}else{
						ex=true;
						break;
					} 
				}//end of 命令选项
				else{
					ex=true;
					break;
				} 
			 }else
			 {
			 	ex=true;
			 	break;
			 }
		}//end of while
		//输出 
		printf("Case %d:",i+1);
		_rep(k,0,26)
		{
			//是选项又出现在字符串中 
			if((node[k].kind&0x1f00f000)==0x1f00f000)
			{
				printf(" -%c",k+'a');
				if((node[k].kind&0x00000fff)!=0)
				{
					//说明有参数，输出参数
					cout<<" "; 
					int value=node[k].kind&0x00000fff;
					_rep(g,value,300)
					{
						if(str[g]!=' '&&str[g]!='\0')
							cout<<str[g];
						else
							break; 
					}
				}
			} 
		}
		cout<<endl;
		freshNode();
		memset(temp,'\0',300);
		memset(str,'\0',300);
		 
	}//end of rep

	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
