//set.find(x),����set�ж�ӦֵΪx�ĵ�����,ʱ�临�Ӷ�ΪO(logN)
#include<stdio.h>
#include<set>
#include<iostream>
using namespace std;
int main()
{
	set<int> st;
	for(int i=0;i<=3;i++)
		st.insert(i);
	set<int>::iterator it=st.find(2);//��set����2,�����������
	cout<<*it;
	return 0; 
 } 
