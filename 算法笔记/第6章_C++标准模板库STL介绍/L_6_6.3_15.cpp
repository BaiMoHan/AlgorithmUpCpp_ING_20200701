//string.find(str2),��str2��str���Ӵ�ʱ,��������str�е�һ�γ��ֵ�λ�� 
//string.find(str2,pos),��str��pos��λ��ʼƥ��str2, ���Ӵ�
//��������Ӵ�,�򷵻�string::npos
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
