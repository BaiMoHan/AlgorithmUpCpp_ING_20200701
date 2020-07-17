//string类型通过+=实现字符串的拼接
#include<iostream>
#include<string>
using namespace std;
int main(){
	string str1="hello",str2="world",str3;
	str3=str1+str2;
	str1+=str2;//相当于<string.h>里面的strcat操作和strcpy操作
	cout<<str3<<endl; 
	cout<<str1<<endl;
	return 0;
} 
