//leng()/size()��ȡstring���͵ĳ���
#include<iostream>
#include<string>
using namespace std;
int main(){
	string str1="hello",str2="world",str3;
	str3=str1+str2;
	str1+=str2;//�൱��<string.h>�����strcat������strcpy����
	cout<<str3.size()<<endl; 
	cout<<str1.length()<<endl;
	return 0;
}  
