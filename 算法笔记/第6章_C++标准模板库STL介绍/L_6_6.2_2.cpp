//set.find(x),返回set中对应值为x的迭代器,时间复杂度为O(logN)
#include<stdio.h>
#include<set>
#include<iostream>
using namespace std;
int main()
{
	set<int> st;
	for(int i=0;i<=3;i++)
		st.insert(i);
	set<int>::iterator it=st.find(2);//在set中找2,返回其迭代器
	cout<<*it;
	return 0; 
 } 
