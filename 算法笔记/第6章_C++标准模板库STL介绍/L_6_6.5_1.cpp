/******************************************
queue<typename> name;
����queue�Ƚ��ȳ������������ݽṹ, 
ֻ��ͨ��queue.front()������Ԫ�غ�queue.back����βԪ��
***********************************************/
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	queue<int> q;
	for(int i=1;i<=5;i++)
		q.push(i);//push(i)���Խ�iѹ�����
	printf("%d %d",q.front(),q.back());
	return 0;
 } 
