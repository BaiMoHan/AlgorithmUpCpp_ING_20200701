//queue.push(x),将x入队
//queue.front(),获取队首元素
//queue.back(),获取队尾元素
//queue.pop()令队首元素出队
//时间复杂度均为1
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	queue<int> q;
	for(int i=1;i<=5;i++)
		q.push(i);
	for(int i=1;i<=3;i++)
		q.pop();//连续出队首元素三次
	printf("%d %d",q.front(),q.back()) ;
	return 0;
 } 
