#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
char str[300];
char temp[300];
struct Node{
	int kind;//�ĸ��ֽ�,0x1f1f1f1f
	//4�ڴ����Ƿ���ѡ��,3�ֽڴ����в���,2�ֽڸ�4λ�����Ƿ�������ַ���,ʣ�µ�12λ�������λ�� 
}node[30];//node[i]���ַ���i+'a',��ʡ�ռ䣬ȫ�ֱ�����ʼΪ0 

void freshNode()//���½ṹ�� 
{
	_rep(i,0,26)
	{
		//ȥ����16λ 
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
		//��������ѡ��
		return true; 
	else
		return false;
}
void readLine(char *str)//��ȡһ�� 
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
int readWord(char* temp,int num)//��ȡһ������
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
	

	//��ȡ����ѡ��
	readLine(str);
	int len=strlen(str); 
	_rep(i,0,len)
	{
		if(str[i]==':')
		{
			//��Ǵ����� 
			node[str[i-1]-'a'].kind|=0x001f0000;
		}else{
			//�����ѡ��
			node[str[i]-'a'].kind|=0x1f000000; 
		}
	}
		

	int n,cnt,t;	//��������,������ 
	bool ex=false; 
	cin>>n;
	getchar();//���˻���
	
	 
	_rep(i,0,n)
	{
		readLine(str); 
		len=strlen(str);//��ȡ�����ַ������� 
		//����ǰ��Ĺ������� 
		cnt=0;
		while(str[cnt]!=' '&&str[cnt]!='\0')
			//�ҵ���һ���ո�
			cnt++;
		
		cnt++; 
		while(cnt<len)
		{
			
			t=readWord(temp,cnt);
			if(t==2&&str[cnt]=='-')
			{
				//�ж��ǲ������� 
				if(str[cnt+1]<='z'&&str[cnt+1]>='a')//˵������������ѡ�� 
				{
					if((node[str[cnt+1]-'a'].kind&0x1f000000)==0x1f000000)
					{
						//������ѡ���ʾ�������ַ�����
						node[str[cnt+1]-'a'].kind|=0x0000f000;
						//��һ���ж��Ƿ��в���
						if((node[str[cnt+1]-'a'].kind&0x001f0000)==0x001f0000)
						{
							//�в�����ѡ��
							cnt+=t;
							cnt++;
							t=readWord(temp,cnt);
							if(judgeTemp())
							{
								//��Ǹò�����λ��
								node[str[cnt-2]-'a'].kind&=0xfffff000;//�������һ�ε�λ�� 
								node[str[cnt-2]-'a'].kind|=cnt;
								cnt+=t;
								cnt++;
							}
						 }else
						 {
						 	//�޲��� ������һ��
						 	cnt+=t;
							cnt++; 
							 
						 }
					}else{
						ex=true;
						break;
					} 
				}//end of ����ѡ��
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
		//��� 
		printf("Case %d:",i+1);
		_rep(k,0,26)
		{
			//��ѡ���ֳ������ַ����� 
			if((node[k].kind&0x1f00f000)==0x1f00f000)
			{
				printf(" -%c",k+'a');
				if((node[k].kind&0x00000fff)!=0)
				{
					//˵���в������������
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
