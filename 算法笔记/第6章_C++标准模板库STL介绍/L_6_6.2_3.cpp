//erase(it)��ɾ��������it����Ӧ��Ԫ��,ͨ������st.find(x),ʱ�临�Ӷ�O(1) 
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
	st.erase(st.find(100));//��ͨ��find���ص�������Ȼ��ɾ��
	for(set<int>::iterator it=st.begin();it!=st.end();it++)//st.end()ָ��������һ��Ԫ�ص���һ��'
		printf("%d ",*it); 
	return 0; 
}
