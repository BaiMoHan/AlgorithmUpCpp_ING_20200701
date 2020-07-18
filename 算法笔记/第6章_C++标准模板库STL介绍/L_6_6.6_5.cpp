//priority_queue内元素优先级的设置
//char int double直接使用的数据类型
//priority_queue<int> q
//priority_queue<int,vector<int>,less<int> >
//第二个参数vector<int>填写的是来承载底层数据结构heap的容易
//第三个参数表示优先级设置,less<int>表示数字大的优先级搞,greater<int>表示数字小的优先级高
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int,vector<int>,greater<int> > q;//表示数字小的优先级高
	q.push(50);
	q.push(6);
	q.push(100);
	printf("%d",q.top());
	return 0; 
 } 
