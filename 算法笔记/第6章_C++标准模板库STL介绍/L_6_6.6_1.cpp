/****************************************
priority_queue优先队列，queue的一种，
队首元素一定是当前队列中优先级最高的元素
如果是int型，则是队列中最大的那个元素
底层使用堆实现
*****************************************/
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int> q;
	q.push(3);
	q.push(5);
	q.push(3100);
	q.push(300);
	printf("%d",q.top());//队首为最大的元素 
	return 0;
 } 
