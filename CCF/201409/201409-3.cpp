#include<string.h>
#include<iostream>
#define N 104
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
char substr1[N];
char substr2[N];	//转换成小写之后的子串 
char str1[N];
char str2[N];	//转换成小写之后的待匹配串 
using namespace std;
int main()
{
	#ifndef OJ
	freopen("201409-3.txt","r",stdin);
	#endif
	int n,mode;
	scanf("%s",substr1);
	cin>>mode>>n;
	int i=0;
	if(mode==0)
	{
		//大小写不敏感，需要先转换 
		while(substr1[i]!='\0')
		{
			//全部换成小写
			if(substr1[i]<='Z'&&substr1[i]>='A')
				substr2[i]=substr1[i]-'A'+'a';
			else
				substr2[i]=substr1[i]; 
			i++;
		}
		substr2[i]='\0';
		_rep(j,0,n)
		{
			scanf("%s",str1);
			i=0;
			//将待匹配串转换为小写 
			while(str1[i]!='\0')
			{
				//全部换成小写
				if(str1[i]<='Z'&&str1[i]>='A')
					str2[i]=str1[i]-'A'+'a';
				else
					str2[i]=str1[i]; 
				i++;
			}
			str2[i]='\0';
			if(strstr(str2,substr2)==NULL)
				continue;
			else
				cout<<str1<<endl; 
		}
	}else{
		//大小写敏感，不需要转换 
		_rep(j,0,n)
		{
			scanf("%s",str1);
			if(strstr(str1,substr1)==NULL)
				continue;
			else
				cout<<str1<<endl; 
		}
	}

	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
