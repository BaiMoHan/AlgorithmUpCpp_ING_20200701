//string::npos作为find函数失配后的返回值
#include<iostream>
#include<string>
using namespace std;
int main()
{
	if(string::npos==-1)
		cout<<"-1 is string::npos"<<endl;
	if(string::npos==4294967295)//看编译器警告提示 
		cout<<"4294967295 is also string::npos"<<endl;
	return 0;
 } 
