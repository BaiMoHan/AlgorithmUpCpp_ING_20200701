//mp.erase(it),itΪ��Ҫɾ����Ԫ�صĵ�����
//ͨ����mp.find(key)һ�����ʹ�� 
//ʱ�临�Ӷ�O��1��
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
