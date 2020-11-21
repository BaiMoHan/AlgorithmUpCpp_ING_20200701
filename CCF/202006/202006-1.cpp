#include<iostream>
#include<cstdio>
#define OJ 98
#define N 1002 
using namespace std;
int x[N],y[N];//点对 
char type[N];//点对类型 
int main()
{
	#ifndef OJ
	freopen("202006-1.txt","r",stdin);
	#endif
	int n;//n个点 
	int m;//m个测试方程 
	int t1,t2,t3;//t1常数,t2为x系数,t3为y的系数 
	cin>>n>>m;//读取n m 
	bool ABREAK=false;	//A类是否提前终止 
	bool BBREAK=false;	//B类是否提前终止
	bool AFIRST=false;	//A类是否已经第一次确定
	bool BFIRST=false;	//B类是否已经第一次确定
	bool ASTATE,BSTATE;	//A类和B类的对于方程的状态 

	//读取n个点对的信息 
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i]>>type[i];
	}
	//读取判别方程并判断 
	for(int j=0;j<m;j++)
	{
		cin>>t1>>t2>>t3;
		for(int i=0;i<n;i++)
		{
			if(type[i]=='A')
			{
				if(AFIRST==false)//此时ASTATE还未确定 
				{
					AFIRST=true;
					ASTATE=(t1+t2*x[i]+t3*y[i]<0);//第一个点来确定ASTATE标记是否小于0 
				}
				else{
					if(ASTATE!=(t1+t2*x[i]+t3*y[i]<0))//A类点状态冲突了 
					{
						printf("No\n");//跳出循环，提前判断结束 
						ABREAK=true;
						break;
					}
				}
			}
			else{
				if(BFIRST==false)
				{
					BFIRST=true;
					BSTATE=(t1+t2*x[i]+t3*y[i]>0);
				}
				else{
					if(BSTATE!=(t1+t2*x[i]+t3*y[i]>0))
					{
						printf("No\n");
						BBREAK=true;
						break;
					}
				}
			}
		}
		if(BBREAK!=true&&ABREAK!=true&&ASTATE==BSTATE)
		{
			printf("Yes\n");
		}
		//每次循环结束后初始化bool变量
		AFIRST=false;
		BFIRST=false;
		BBREAK=false;
		ABREAK=false;	
	}
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
