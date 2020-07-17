//通过迭代器访问map内元素 
//it->first访问键，it->second来访问值
#include<stdio.h>
#include<map>
using namespace std;
int main()
{
	map<char,int> mp;
	mp['m']=10;
	mp['r']=20;
	mp['a']=40;
	for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
		printf("%c %d\n",it->first,it->second);
		//从输出上可以看到键从小到大自动排序,内层红黑树实现 
	return 0;
 } 
