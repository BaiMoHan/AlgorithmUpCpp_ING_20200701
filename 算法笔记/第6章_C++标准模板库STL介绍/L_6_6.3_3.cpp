//通过string类型的迭代器访问string容器的内容
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string str="abcd";
	for(string::iterator it=str.begin();it!=str.end();it++)
		printf("%c",*it);
	return 0;
	
 } 
