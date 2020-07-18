//结构体的优先级设置,需要用C++对<小于号重载
//重载大于号会编译错误,从数学来讲只需要重载小于号
//f1>f2等价于判断f2<f1
//f1==f2等价于判断 !(f1<f2)&&!(f2<f1) 
#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct fruit{
	string name;
	int price;
	friend bool operator < (fruit f1,fruit f2){
		return f1.price>f2.price;	//价格低的优先级高，优先队列与sort里面的cmp是反着来 
	}
}f1,f2,f3;
int main()
{
	priority_queue<fruit> q;
	f1.name="苹果";
	f1.price=20 ;
	f2.name="桃子";
	f2.price=15;
	f3.name="梨子";
	f3.price=100;
	q.push(f1);
	q.push(f2);
	q.push(f3);
	cout<<q.top().name<<" "<<q.top().price<<endl;
	return 0; 
 } 
