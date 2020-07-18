//priority_queue.empty()判断优先队列是否为空
#include<stdio.h>
#include<queue> 
using namespace std;
int main()
{
	priority_queue<int> q;
	if(q.empty()==true){
		printf("Empty!\n");
	}
	else{
		printf("No empty!\n");
	}
	q.push(100);
	if(q.empty()==true){
		printf("Empty!\n");
	}
	else{
		printf("No empty!\n");
	}
	return 0;
}
