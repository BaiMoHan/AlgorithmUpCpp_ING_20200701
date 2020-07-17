//leng()/size()获取string类型的长度
#include<iostream>
#include<string>
using namespace std;
int main(){
	string str1="hello",str2="world",str3;
	str3=str1+str2;
	str1+=str2;//相当于<string.h>里面的strcat操作和strcpy操作
	cout<<str3.size()<<endl; 
	cout<<str1.length()<<endl;
	return 0;
}  
