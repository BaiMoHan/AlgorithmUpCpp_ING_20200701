//string.erase(it)��ɾ��it������ָ�򵥸�Ԫ��
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str="hello world";
	str.erase(str.begin()+5);
	cout<<str<<endl;
	return 0;
 } 
