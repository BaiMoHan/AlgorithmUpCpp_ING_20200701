//map.find(key),返回键为key的映射的迭代器,时间复杂度为O(logN)
#include<stdio.h>
#include<map>
using namespace std;
int main()
{
	map<char,int> mp;
	mp['m']=10;
	mp['r']=20;
	mp['a']=40;	
	map<char,int>::iterator it=mp.find('r');
	printf("%c %d",it->first,it->second);
	return 0;
 } 
