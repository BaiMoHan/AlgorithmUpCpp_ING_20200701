//�ṹ������ȼ�����,��Ҫ��C++��<С�ں�����
//���ش��ںŻ�������,����ѧ����ֻ��Ҫ����С�ں�
//f1>f2�ȼ����ж�f2<f1
//f1==f2�ȼ����ж� !(f1<f2)&&!(f2<f1) 
#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct fruit{
	string name;
	int price;
	friend bool operator < (fruit f1,fruit f2){
		return f1.price>f2.price;	//�۸�͵����ȼ��ߣ����ȶ�����sort�����cmp�Ƿ����� 
	}
}f1,f2,f3;
int main()
{
	priority_queue<fruit> q;
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
