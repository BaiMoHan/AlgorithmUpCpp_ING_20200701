//string.insert(it,it2,it3),������Ϊ��������ʱ�临�Ӷ�ΪO(N)
//itΪԭ�ַ�����������λ��,it2��it3Ϊ�������ַ�������β������,[it2,it3)Ϊ���������
#include<iostream>
#include<string>
using namespace std;
int main(){
	string str="abcdxyz",str2="opq";
	//������λ����str2,����c��d֮�����
	str.insert(str.begin()+3,str2.begin(),str2.end());
	cout<<str<<endl;
	return 0; 
} 
 
