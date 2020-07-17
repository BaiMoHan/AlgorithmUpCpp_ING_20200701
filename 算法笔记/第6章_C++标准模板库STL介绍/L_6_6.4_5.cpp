//map.erase(key),key为欲删除的映射的键,时间复杂度为O(logN)
#include<stdio.h>
#include<map>
using namespace std;
int main()
{
	map<char,int> mp;
	mp['m']=10;
	mp['r']=20;
	mp['a']=40;	
	mp.erase('r');
	for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
		printf("%c %d\n",it->first,it->second);
	return 0; 
 } 
