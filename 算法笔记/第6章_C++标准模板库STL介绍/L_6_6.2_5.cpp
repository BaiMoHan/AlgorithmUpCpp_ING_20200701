//erase(first,last),删除区间[first,last)区间内的元素
//first和last都是迭代器,时间复杂度为O(last-first) 
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
	set<int>::iterator it=st.find(200);
	st.erase(it,st.end());//删除200一直到最后一个元素 
	for(set<int>::iterator it=st.begin();it!=st.end();it++)
		printf("%d ",*it);
	return 0;
 } 
