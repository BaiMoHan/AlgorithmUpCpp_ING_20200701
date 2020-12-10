#include<iostream>
#include<cstdio>
using namespace std;
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
int day[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
int judgeYear(int y)//判断是否闰年
{
	if((y%4==0&&y%100!=0)||y%400==0)
		return 1;
	else
		return 0;
 } 
int main()
{
	#ifndef OJ
	freopen("201503-3.txt","r",stdin);
	#endif
	//m月的第k个星期t，不存在输出none 
	int m,k,t,y1,y2;
	cin>>m>>k>>t>>y1>>y2;
	bool flag=true;//标记是否找到 
	int count=-1,mode=0,id=0,res=0;
	//1950 1. 1 星期二
	//算距离的天数
	_rep(i,1850,y1-1)
	{
		mode=judgeYear(i);
		_rep(j,0,11)
		{
			count+=day[mode][j];
		}
		count%=7;//取模防止count溢出 
	 } 
	
	//统计 y1到y2之间的
	//先找到y1/m/1是星期几 
	
	_rep(i,y1,y2)
	{
		id=count;
		mode=judgeYear(i);
		_rep(j,0,m-2)
		{
			count+=day[mode][j];
		}
		count%=7;

		_rep(z,1,day[mode][m-1])
		{
			count++;
			count%=7;
			if(count==((t+5)%7))
			{
				res++;
				if(res==k)
				{
					flag=false;
					cout<<i<<'/';
					printf("%02d/%02d\n",m,z);
					break;
				}
			}
			
		}
		if(flag==true)
		{
			cout<<"none"<<endl;	
		}
		flag=true;
		res=0;
		//进入下一年，把当前年走完 
		count=id;
		_rep(j,0,11)
		{
			count+=day[mode][j];
		}
		count%=7;
	 } 
	 
	 
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
