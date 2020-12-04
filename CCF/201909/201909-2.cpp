#include<iostream>
using namespace std;
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define N 1004
struct tree{
	int num;	//果子数目
	int flag;	//标记是否掉果子，1表示掉了 
	tree(){
		num=0;
		flag=0;
	} 
}node[N]; 
int main()
{
	#ifndef OJ
	freopen("201909-2.txt","r",stdin);
	#endif
	int n;	//果树棵树 
	cin>>n;
	int k;	//每棵树的操作次数 
	int D=0;//掉落果树数目
	int E=0;//连续三棵掉落的组数 
	long T=0;//剩下的果子数目 
	int temp=0;
	bool count=false;	//标记是否已经统计过掉落 
	//读取并判断 
	_rep(i,0,n)
	{
		//读取操作次数 
		cin>>k;
		//读取果树的初始果子数目 
		cin>>node[i].num;
		_rep(j,1,k)
		{
			//读取数值 
			cin>>temp;
			//大于0说明没有疏果 
			if(temp>0){	//判断是否掉落了
				if(node[i].num>temp) 
				{
					node[i].flag=1;
					if(count==false)
					{
						D++;	//掉落的果树数目自增 
						count=true;
					}
				}
				node[i].num=temp;
			}else{
				node[i].num+=temp;	//疏果 
			}
		}
		count=false;	//恢复统计标志 
	}
	//统计T和E
	_rep(i,0,n)
	{
		T+=node[i].num;
		//判断连续相邻的三棵树 
		if(node[(i+n-1)%n].flag&&node[(i+1)%n].flag&&node[i].flag&&n>2)
			E++;
	 } 
	cout<<T<<" "<<D<<" "<<E;

	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
