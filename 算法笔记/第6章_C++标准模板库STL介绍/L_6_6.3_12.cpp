//string.clear()清空字符串,时间复杂度一般为O(1)
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	string str="hello world";
	str.clear();
	printf("%d %d",str.length(),str.size());
	return 0;
 } 
