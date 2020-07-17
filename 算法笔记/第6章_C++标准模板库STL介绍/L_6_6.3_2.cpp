//string类读入和输出整个字符串用cin和cout
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cin>>str;
	cout<<str;
	printf("\n\n%s",str.c_str());
	return 0; 
 } 
