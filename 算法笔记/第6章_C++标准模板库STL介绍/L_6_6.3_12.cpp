//string.clear()����ַ���,ʱ�临�Ӷ�һ��ΪO(1)
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	string str="hello world";
	str.clear();
	printf("%d %d",str.length(),str.size());
	return 0;
 } 
