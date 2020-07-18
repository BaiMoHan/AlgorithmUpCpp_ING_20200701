//queue.empty()检测queue是否为空,返回true则为空
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	queue<int> q;
	if(q.empty()==true)
		printf("empty!\n");
	else
		printf("No empty\n");
	q.push(100);
	if(q.empty()==true)
		printf("empty!\n");
	else
		printf("No empty\n");
	return 0;
		
 } 
 //使用q.front()和q.back()前，必须先用q.empty()判断队列是否为空,否则可能出现错误 
