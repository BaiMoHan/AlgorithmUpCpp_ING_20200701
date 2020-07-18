//priority_queue.push(x),将x入队，时间复杂度O(logN) 
//priority_queue.top(),获得队首元素，时间复杂度O(1) 
//priority_queue.pop(),令队首元素出队,时间复杂度O(logN)
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int> q;
	q.push(2);
	q.push(4);
	q.push(500);
	printf("top=%d\n",q.top());
	q.pop();
	printf("top=%d",q.top());
	return 0;
 } 
