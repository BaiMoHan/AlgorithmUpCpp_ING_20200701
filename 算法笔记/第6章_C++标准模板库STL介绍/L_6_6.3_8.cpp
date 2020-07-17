//string.insert(it,it2,it3),参数均为迭代器，时间复杂度为O(N)
//it为原字符串的欲插入位置,it2和it3为待插入字符串的首尾迭代器,[it2,it3)为插入的内容
#include<iostream>
#include<string>
using namespace std;
int main(){
	string str="abcdxyz",str2="opq";
	//在三号位插入str2,即在c和d之间插入
	str.insert(str.begin()+3,str2.begin(),str2.end());
	cout<<str<<endl;
	return 0; 
} 
 
