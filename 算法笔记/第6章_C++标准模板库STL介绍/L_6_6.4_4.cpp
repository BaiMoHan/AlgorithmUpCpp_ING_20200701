//mp.erase(it),it为需要删除的元素的迭代器
//通常与mp.find(key)一起配合使用 
//时间复杂度O（1）
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
	mp.erase(it);
	for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
		printf("%c %d\n",it->first,it->second);
	return 0; 
 } 
