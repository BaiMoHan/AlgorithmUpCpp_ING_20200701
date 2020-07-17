//string.insert(pos,string)在pos号位置插入字符串string
//即插入串前面保留pos个字符，时间复杂度为O(N) 
#include<iostream>
#include<string>
using namespace std;
int main(){
	string str1="hello",str2="world",str3;
	str3=str1+str2;
	str1+=str2;//相当于<string.h>里面的strcat操作和strcpy操作
	str1.insert(5,str3);
	cout<<str3<<endl; 
	cout<<str1<<endl;
	return 0;
}  
