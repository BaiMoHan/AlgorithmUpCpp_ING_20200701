//queue.size()后去队列内元素的个数
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	queue<int> q;
	for(int i=1;i<=5;i++)
		q.push(i);//push(i)用以将i压入队列
	printf("%d",q.size());
	return 0;
 }  
