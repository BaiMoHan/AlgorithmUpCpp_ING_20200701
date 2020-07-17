//set.clear()用来清空set内的所有元素,时间复杂度为O(N)
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
	st.clear(); 
	printf("%d ",st.size())	;
	return 0;
}  
