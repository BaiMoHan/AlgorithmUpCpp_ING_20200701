/**********************************************
string���Ͷ��ַ������ò��������˷�װ
ע��<string>��<string.h>�ǲ�ͬ�Ŀ��ļ�
���巽ʽ��
string str; 

string str="hello world";
***********************************************/
//ͨ���±����string����
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main(){
	string str="abcd";
	for(int i=0;i<str.length();i++)
		printf("%c\n",str[i]);
	printf("%s",str.c_str());//��printf�������str
	cout<<str;//��һ�㶼�ǲ�ȡC++��������� 
	return 0; 
} 
