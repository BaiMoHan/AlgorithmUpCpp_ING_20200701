//string::npos��Ϊfind����ʧ���ķ���ֵ
#include<iostream>
#include<string>
using namespace std;
int main()
{
	if(string::npos==-1)
		cout<<"-1 is string::npos"<<endl;
	if(string::npos==4294967295)//��������������ʾ 
		cout<<"4294967295 is also string::npos"<<endl;
	return 0;
 } 
