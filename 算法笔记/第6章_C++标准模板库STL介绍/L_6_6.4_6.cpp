//map.erase(first,last),������Ϊ������
//ɾ������[first,last)�����ڵ�Ԫ�أ�ʱ�临�Ӷ�ΪO(last-first)
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
	mp.erase(it,mp.end());//ɾ��it֮�������ӳ��
	for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
		printf("%c %d\n",it->first,it->second);
	return 0;  
 } 
