//set�Զ������Ҳ����ظ�Ԫ�ص�����
/*******************************************
set<typename> name;
set<int> name;
set<double> name;
set<char> name;
set<node> name;//nodeΪ�ṹ�� 
set<int> a[arraysize] 

set.insert(x),����Ԫ��x��ʱ�临�Ӷ�ΪO(logN) 
**********************************************/ 
#include<stdio.h>
#include<set>
using namespace std;
int main()
{
	set<int> st;
	st.insert(1);
	st.insert(2);
	st.insert(3);
	st.insert(1);//set���Զ��޳� 
	st.insert(2);
	//set������Ԫ��ֻ֧�ֵ��������ʣ���֧��vi[i]������
	for(set<int>::iterator it=st.begin();it!=st.end();it++) //��֧��it<st.end()��д��
	{
//		printf("%d ",st[1]);����д�� 
		printf("%d ",*it);//���յ����������� 
	 } 
	return 0;
 } 










