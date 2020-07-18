/******************************************
queue<typename> name;
队列queue先进先出的限制性数据结构, 
只能通过queue.front()访问首元素和queue.back访问尾元素
***********************************************/
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	queue<int> q;
	for(int i=1;i<=5;i++)
		q.push(i);//push(i)用以将i压入队列
	printf("%d %d",q.front(),q.back());
	return 0;
 } 
