//string.insert(pos,string)��pos��λ�ò����ַ���string
//�����봮ǰ�汣��pos���ַ���ʱ�临�Ӷ�ΪO(N) 
#include<iostream>
#include<string>
using namespace std;
int main(){
	string str1="hello",str2="world",str3;
	str3=str1+str2;
	str1+=str2;//�൱��<string.h>�����strcat������strcpy����
	str1.insert(5,str3);
	cout<<str3<<endl; 
	cout<<str1<<endl;
	return 0;
}  
