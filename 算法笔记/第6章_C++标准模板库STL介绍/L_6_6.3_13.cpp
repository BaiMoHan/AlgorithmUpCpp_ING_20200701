//string.substr(pos,len)���ش�pos��λ��ʼ������Ϊlen���Ӵ�,ʱ�临�Ӷ�ΪO(len)
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
