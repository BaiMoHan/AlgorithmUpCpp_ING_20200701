#include<string.h>
#include<iostream>
#define N 104
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
char substr1[N];
char substr2[N];	//ת����Сд֮����Ӵ� 
char str1[N];
char str2[N];	//ת����Сд֮��Ĵ�ƥ�䴮 
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
		//��Сд�����У���Ҫ��ת�� 
		while(substr1[i]!='\0')
		{
			//ȫ������Сд
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
			//����ƥ�䴮ת��ΪСд 
			while(str1[i]!='\0')
			{
				//ȫ������Сд
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
		//��Сд���У�����Ҫת�� 
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
