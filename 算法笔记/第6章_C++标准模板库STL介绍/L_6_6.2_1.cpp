//set自动有序且不含重复元素的容器
/*******************************************
set<typename> name;
set<int> name;
set<double> name;
set<char> name;
set<node> name;//node为结构体 
set<int> a[arraysize] 

set.insert(x),插入元素x，时间复杂度为O(logN) 
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
	st.insert(1);//set会自动剔除 
	st.insert(2);
	//set容器内元素只支持迭代器访问，不支持vi[i]这样的
	for(set<int>::iterator it=st.begin();it!=st.end();it++) //不支持it<st.end()的写法
	{
//		printf("%d ",st[1]);错误写法 
		printf("%d ",*it);//按照递增有序排列 
	 } 
	return 0;
 } 










