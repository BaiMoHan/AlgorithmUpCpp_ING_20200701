//�������ȶ��У������غ���ж�ؽṹ�����棬�����ص���С����()
//����ʹ�õڶ��ַ�ʽ���������ȶ���
//priority_queue<fruit,vector<fruit>,cmp> q;
//�����ǻ����������ͻ�������STL����(����set),Ҳ����ͨ��ͬ���ķ�ʽ�������ȼ� 
#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct fruit{
	string name;
	int price;
}f1,f2,f3;
struct cmp{
	bool operator () (fruit f1,fruit f2){
		return f1.price>f2.price;//��С�����ȼ��� 
	}
}; 
int main()
{
	priority_queue<fruit,vector<fruit>,cmp> q;
	f1.name="ƻ��";
	f1.price=20 ;
	f2.name="����";
	f2.price=15;
	f3.name="����";
	f3.price=100;
	q.push(f1);
	q.push(f2);
	q.push(f3);	
	cout<<q.top().name<<" "<<q.top().price<<endl;
	return 0;
}
/**********************************************************
����ṹ���ڵ����ݽ�Ϊ�Ӵ�(����������ַ�����������),����ʹ������
�����Ч��

friend bool operator < (const fruit &f1,const fruit &f2){
	return f1.price>f2.price;
}

bool operator () (const fruit &f1,const fruit &f2){
	return f1.price>f2.price;
}


priority_queue���Խ��һЩ̰�����⣬Ҳ���Զ�Dijkstra�㷨�����Ż�
ʹ��top()ǰ������empty()�ж϶����Ƿ�Ϊ��
************************************************************/ 













 
