//priority_queue.size()获取优先队列元素的个数
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
	printf("%d",q.size());//队首为最大的元素 
	return 0;	
}
