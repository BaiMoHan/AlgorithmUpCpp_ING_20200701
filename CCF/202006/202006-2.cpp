#include<iostream>
#include<vector>
#include<utility>
#define OJ 98
#define _rep(i,a,b) for(int i=(a);i<(b);++i) //循环宏定义
using namespace std; 
int main()
{
	#ifndef OJ
	freopen("202006-2.txt","r",stdin);
	#endif
	vector<pair<int,int> > v;
	int n;	//维度
	int a;	//第一个向量的个数
	int b;	//第二个向量的个数 
	long long res=0;
	cin>>n>>a>>b;
	
	int index,value;//中间变量 
	_rep(i,0,a)	//读入第一个稀疏向量 
	{
		cin>>index>>value;
		v.push_back(make_pair(index,value));
	}
	int j=0;
	_rep(i,0,b)//读取第二个稀疏向量并判断 
	{
		cin>>index>>value;
		while(j<a)
		{
			if(index>v[j].first)	//第一个向量的index小了，第一个向量移到下一个 
				j++;
			else if(index<v[j].first)	//第一个向量的index大了， 第二个向量移到
				break;
			else	//刚好对上位置
			{
				res+=value*v[j].second;
				j++;
			} 
		}	
	}
	cout<<res<<endl;
	
	#ifndef	OJ
	fclose(stdin);
	#endif
}
