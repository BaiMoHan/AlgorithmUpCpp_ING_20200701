//priority_queue��Ԫ�����ȼ�������
//char int doubleֱ��ʹ�õ���������
//priority_queue<int> q
//priority_queue<int,vector<int>,less<int> >
//�ڶ�������vector<int>��д���������صײ����ݽṹheap������
//������������ʾ���ȼ�����,less<int>��ʾ���ִ�����ȼ���,greater<int>��ʾ����С�����ȼ���
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int,vector<int>,greater<int> > q;//��ʾ����С�����ȼ���
	q.push(50);
	q.push(6);
	q.push(100);
	printf("%d",q.top());
	return 0; 
 } 
