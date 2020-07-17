/**********************************************
string类型对字符串常用操作进行了封装
注意<string>和<string.h>是不同的库文件
定义方式：
string str; 

string str="hello world";
***********************************************/
//通过下表访问string内容
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main(){
	string str="abcd";
	for(int i=0;i<str.length();i++)
		printf("%c\n",str[i]);
	printf("%s",str.c_str());//用printf输出完整str
	cout<<str;//但一般都是采取C++的输入输出 
	return 0; 
} 
