//map.size()��ȡӳ��Ķ���,ʱ�临�Ӷ�ΪO(1)
#include<stdio.h>
#include<map>
using namespace std;
int main()
{
	map<char,int> mp;
	mp['m']=10;
	mp['r']=20;
	mp['a']=40;	
	printf("%d",mp.size());
	return 0;
 } 
