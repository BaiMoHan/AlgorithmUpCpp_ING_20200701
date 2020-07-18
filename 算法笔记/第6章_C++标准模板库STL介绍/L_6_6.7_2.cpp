//stack.push(x),将x入栈,时间复杂度为O(1) 
//stack.top(),获取栈顶元素,时间复杂度为O(1) 
//stack.pop(),弹出栈顶元素,时间复杂度为O(1) 
#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	stack<int> st;
	for(int i=0;i<5;i++)
		st.push(i);
	for(int i=1;i<=3;i++)
		st.pop();
	printf("%d",st.top());
	return 0;
}
