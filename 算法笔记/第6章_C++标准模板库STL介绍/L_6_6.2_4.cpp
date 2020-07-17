//erase(x)，删除值为x的元素,时间复杂度为O(logN)
 #include<stdio.h>
#include<set>
using namespace std;
int main()
{
	set<int> st;
	st.insert(100);
	st.insert(200);
	st.insert(300);
	st.insert(400);
	st.insert(500);
	st.erase(200);//先通过find返回迭代器，然后删除
	for(set<int>::iterator it=st.begin();it!=st.end();it++)//st.end()指向的是最后一个元素的下一个'
		printf("%d ",*it); 
	return 0; 
}
