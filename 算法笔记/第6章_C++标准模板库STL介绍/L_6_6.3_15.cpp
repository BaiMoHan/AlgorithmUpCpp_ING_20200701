//string.find(str2),当str2是str的子串时,返回其在str中第一次出现的位置 
//string.find(str2,pos),从str的pos号位开始匹配str2, 找子串
//如果不是子串,则返回string::npos
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str="welcome to the Earth";
	string str2="co";
	string str3="th";
	string str4="my";
	if(str.find(str2)!=string::npos)
		cout<<str.find(str2)<<endl;
	if(str.find(str3,15)!=string::npos)
		cout<<str.find(str3,15)<<endl;
	if(str.find(str4)!=string::npos)
		cout<<str.find(str4)<<endl;
	else
		cout<<"no position for "<<str4<<endl;
	return 0;
 } 
