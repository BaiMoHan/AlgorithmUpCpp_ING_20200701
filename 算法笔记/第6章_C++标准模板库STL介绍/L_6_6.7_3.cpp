//stack.empty()ÅĞ¶ÏÔªËØÊÇ·ñÎª¿Õ
#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	stack<int> st;
	if(st.empty()==true)
		printf("Empty!\n");
	else
		printf("Not empty!\n");
	st.push(100);
	if(st.empty()==true)
		printf("Empty!\n");
	else
		printf("Not empty!\n");
	return 0;
 } 
