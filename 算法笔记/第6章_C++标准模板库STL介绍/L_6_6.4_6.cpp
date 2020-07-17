//map.erase(first,last),参数均为迭代器
//删除区间[first,last)区间内的元素，时间复杂度为O(last-first)
#include<stdio.h>
#include<map>
using namespace std;
int main()
{
	map<char,int> mp;
	mp['m']=10;
	mp['r']=20;
	mp['a']=40;		
	map<char,int>::iterator it=mp.find('m');
	mp.erase(it,mp.end());//删除it之后的所有映射
	for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
		printf("%c %d\n",it->first,it->second);
	return 0;  
 } 
