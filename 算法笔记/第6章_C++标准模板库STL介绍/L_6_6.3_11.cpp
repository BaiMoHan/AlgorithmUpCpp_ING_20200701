//string.erase(pos,length)
//posΪ��Ҫ��ʼɾ������ʼλ��,lengthΪɾ�����ַ�����
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
