//string.substr(pos,len)返回从pos号位开始、长度为len的子串,时间复杂度为O(len)
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str="welcome to the Earth";
	cout<<str.substr(8,2)<<endl;
	cout<<str.substr(11,3)<<endl;
	cout<<str.substr(15,5)<<endl;
	return 0;
 } 
