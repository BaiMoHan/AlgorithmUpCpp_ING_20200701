#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
vector<string> vt;
map<string,string> mp;
int main()
{
	#ifndef OJ
	freopen("201509-3.txt","r",stdin);
	#endif
	int m,n;
	cin>>m>>n;
	getchar();//读取换行符 
	string temp,key,value;
	int p1,p2;
	_rep(i,0,m)
	{
		getline(cin,temp);
		vt.push_back(temp);
	}
	
	_rep(i,0,n)
	{
		cin>>key;
		getline(cin,value);
		mp[key]=value.substr(2,value.length()-3);
	}
	
	//对每一行字符串进行处理 
	_rep(i,0,m)
	{
		p1=0;//每次处理前，先将前指针位置p1置为0
		while(true)
		{
			if((p1=vt[i].find("{{ ",p1))==(int)string::npos)
				break;
			if((p2=vt[i].find(" }}",p1))==(int)string::npos)
				break;
			//提取可能要替换的字符串 
			key=vt[i].substr(p1+3,p2-p1-3); 
			vt[i].replace(p1,p2+3-p1,mp.count(key)?mp[key]:"");
			//p1移动到后面
			p1+=mp.count(key)?key.length():0; 
		 } 
	}
	_rep(i,0,m)
		cout<<vt[i]<<endl;
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
