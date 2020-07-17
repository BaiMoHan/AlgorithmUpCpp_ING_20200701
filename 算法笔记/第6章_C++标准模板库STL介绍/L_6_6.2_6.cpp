//set.size()获取set内元素的个数,时间复杂度为O(1)
#include<stdio.h>
#include<set>
using namespace std;
int main(){
	set<int> st;
	st.insert(100);
	st.insert(200);
	st.insert(300);
	st.insert(400);
	st.insert(500);	
	st.insert(500);	
	st.insert(500);	
	st.insert(500);	
	printf("%d ",st.size())	;
	return 0;
} 
