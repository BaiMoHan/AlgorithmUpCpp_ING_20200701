//string.erase(it)，删除it迭代器指向单个元素
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
