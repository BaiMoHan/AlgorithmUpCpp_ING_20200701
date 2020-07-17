//string.erase(pos,length)
//pos为需要开始删除的起始位置,length为删除的字符个数
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str="hello world";
	str.erase(5,2);
	cout<<str;
	return 0;
 } 
