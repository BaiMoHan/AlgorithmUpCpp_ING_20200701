//string.replace(pos,len,str2)把str从pos尾开始,长度为len的子串替换为str2
//string.replace(it1,it2,str2)把str的迭代器[it1,it2)范围的子串替换为str2
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
