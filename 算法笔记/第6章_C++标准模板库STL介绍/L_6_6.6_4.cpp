//priority_queue.size()��ȡ���ȶ���Ԫ�صĸ���
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
	printf("%d",q.size());//����Ϊ����Ԫ�� 
	return 0;	
}
