//ͨ������������map��Ԫ�� 
//it->first���ʼ���it->second������ֵ
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
		//������Ͽ��Կ�������С�����Զ�����,�ڲ�����ʵ�� 
	return 0;
 } 
