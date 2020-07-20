//使用reverse(it,it2)对容器内元素进行反转
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
	reverse(str.begin()+2,str.begin()+6);//对str[2]~str[5]进行反转
	for(int i=0;i<str.length();i++)
		printf("%c",str[i]);
	return 0; 
}
