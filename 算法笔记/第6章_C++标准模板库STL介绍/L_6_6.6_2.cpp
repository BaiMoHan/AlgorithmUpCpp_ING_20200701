//priority_queue.push(x),��x��ӣ�ʱ�临�Ӷ�O(logN) 
//priority_queue.top(),��ö���Ԫ�أ�ʱ�临�Ӷ�O(1) 
//priority_queue.pop(),�����Ԫ�س���,ʱ�临�Ӷ�O(logN)
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
