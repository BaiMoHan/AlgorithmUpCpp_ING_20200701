//string.erase(first,erase),������Ϊ������,ɾ��[first,erase)
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str="hello world";
	str.erase(str.begin()+3,str.end()-1);//�������һ���ַ�
	cout<<str;
	return 0; 
}
 
