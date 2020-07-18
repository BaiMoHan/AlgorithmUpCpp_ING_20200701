//STL容器stack栈，后进先出，只能通过top()来访问栈顶元素
#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	stack<int> st;
	for(int i=1;i<5;i++)
		st.push(i);
	printf("%d",st.top());
	return 0;
 } 
