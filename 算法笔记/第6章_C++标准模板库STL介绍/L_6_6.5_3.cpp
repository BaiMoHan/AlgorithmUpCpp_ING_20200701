//queue.empty()���queue�Ƿ�Ϊ��,����true��Ϊ��
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
 //ʹ��q.front()��q.back()ǰ����������q.empty()�ж϶����Ƿ�Ϊ��,������ܳ��ִ��� 
