//ʹ��reverse(it,it2)��������Ԫ�ؽ��з�ת
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str="abcdefghi";
	for(int i=0;i<str.length();i++)
		printf("%c",str[i]);
	printf("\n\n");
	reverse(str.begin()+2,str.begin()+6);//��str[2]~str[5]���з�ת
	for(int i=0;i<str.length();i++)
		printf("%c",str[i]);
	return 0; 
}
