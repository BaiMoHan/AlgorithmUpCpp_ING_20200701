//queue.size()��ȥ������Ԫ�صĸ���
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	queue<int> q;
	for(int i=1;i<=5;i++)
		q.push(i);//push(i)���Խ�iѹ�����
	printf("%d",q.size());
	return 0;
 }  
