//map.clear()���map�е�����Ԫ��,���Ӷ�ΪO(N)
#include<stdio.h>
#include<map>
using namespace std;
int main()
{
	map<char,int> mp;
	mp['m']=10;
	mp['r']=20;
	mp['a']=40;	
	mp.clear();
	printf("%d",mp.size());
	return 0;
 } 
