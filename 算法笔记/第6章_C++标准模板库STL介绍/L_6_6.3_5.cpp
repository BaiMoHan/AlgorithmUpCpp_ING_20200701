//ͨ����ͨ���������ֱ�Ӷ�string���Ͳ���,�Ƚϴ�С���ֵ���
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	string str1="aa",str2="aaa",str3="abc",str4="xyz";
	if(str1<str2)
		printf("str1<str2\n");
	if(str1!=str3)
		printf("str1!=str3\n");
	if(str4>=str3)
		printf("str4>=str3\n");
	return 0;
 } 
