//string.replace(pos,len,str2)��str��posβ��ʼ,����Ϊlen���Ӵ��滻Ϊstr2
//string.replace(it1,it2,str2)��str�ĵ�����[it1,it2)��Χ���Ӵ��滻Ϊstr2
#include<iostream>
#include<string>
using namespace std;
int main() 
{
	string str="012346789ABCDEF";
	string str2="hello";
	string str3="world";
	cout<<str.replace(3,2,str2)<<endl;
	cout<<str.replace(10,2,str3)<<endl;
	return 0;
}
