//stack.size()返回stack内元素的个数,时间复杂度O(1)
#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	stack<int> st;
	for(int i=1;i<=5;i++)
		st.push(i);
	printf("%d",st.size());
	return 0;
 } 
