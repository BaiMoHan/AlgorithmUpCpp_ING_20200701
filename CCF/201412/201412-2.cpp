#include<iostream>
using namespace std;
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define N 503
#define E 0	//向东
#define WS 1	//向西南
#define S 2	//向南
#define EN 3	//向东北 
int mp[N][N];
struct node{
	int row;
	int rol;
}dic[4]={{0,1},{1,-1},{1,0},{-1,1}};//四个方向的位置变换 
int main()
{
	#ifndef OJ
	freopen("201412-2.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	_rep(i,0,n)
		_rep(j,0,n)
			cin>>mp[i][j];
	bool flag=false;
	int i=0,j=0;
	int num=0;
	int state=0;	//一开始是向东
	cout<<mp[0][0]; 
	while(i!=n-1||j!=n-1)
	{
		i+=dic[state].row;
		j+=dic[state].rol;
		cout<<" "<<mp[i][j];
		
		//根据当前的state和位置判断下一个state
		if(state==E&&i==0){	//只有在第一行向东才向西南 
			state=WS;	//下一次向西南 
		}else if(state==E&&i==n-1){	//最后一行向东后向东北 
			//向东到了右边界
			state=EN;	//下一次向东北 
		}else if(state==S&&j==0){
			//在左边界向南，但是没有到达下边界
			state=EN;	//向东北 
		}else if(state==S&&j==n-1){
			//在右边界向南,但是没有到达最后一个
			//向西南
			state=WS; 
		}else if(state==WS&&i==n-1){//当西南到达右边界且西南方到了下边界 
			state=E;	//下一次向东 
		}else if(state==WS&&j==0){
			//西南方到达左边界 
			state=S;	//继续向南 
		}else if(state==EN&&j==n-1){
			//东北到达右边界 
			state=S;	//向南 
		}else if(state==EN&&i==0){
			//东北到上边界
			state=E;//向东 
		}
	}
	
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
 
