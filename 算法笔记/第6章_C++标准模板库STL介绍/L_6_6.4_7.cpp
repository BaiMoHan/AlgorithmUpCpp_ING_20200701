//map.size()获取映射的对数,时间复杂度为O(1)
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
