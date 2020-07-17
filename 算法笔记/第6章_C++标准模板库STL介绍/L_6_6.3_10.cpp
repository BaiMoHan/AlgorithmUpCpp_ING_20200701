//string.erase(first,erase),参数均为迭代器,删除[first,erase)
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str="hello world";
	str.erase(str.begin()+3,str.end()-1);//保留最后一个字符
	cout<<str;
	return 0; 
}
 
