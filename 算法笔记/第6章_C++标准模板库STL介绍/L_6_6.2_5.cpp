//erase(first,last),ɾ������[first,last)�����ڵ�Ԫ��
//first��last���ǵ�����,ʱ�临�Ӷ�ΪO(last-first) 
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
	st.erase(it,st.end());//ɾ��200һֱ�����һ��Ԫ�� 
	for(set<int>::iterator it=st.begin();it!=st.end();it++)
		printf("%d ",*it);
	return 0;
 } 
