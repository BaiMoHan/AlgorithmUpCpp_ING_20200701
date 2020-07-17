//map.clear()清空map中的所有元素,复杂度为O(N)
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
