//queue.push(x),��x���
//queue.front(),��ȡ����Ԫ��
//queue.back(),��ȡ��βԪ��
//queue.pop()�����Ԫ�س���
//ʱ�临�ӶȾ�Ϊ1
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	queue<int> q;
	for(int i=1;i<=5;i++)
		q.push(i);
	for(int i=1;i<=3;i++)
		q.pop();//����������Ԫ������
	printf("%d %d",q.front(),q.back()) ;
	return 0;
 } 
