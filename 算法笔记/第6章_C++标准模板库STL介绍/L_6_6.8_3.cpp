//pair常见又两个用途
//1.用来代替二元结构体及其构造函数,可以节省编码时间
//2.作为map的键值对来进行插入
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	map<string,int> mp;
	mp.insert(make_pair("heihei",5));
	mp.insert(pair<string,int>("haha",66));
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
		cout<<it->first<<" "<<it->second<<endl;
	return 0;
 } 
