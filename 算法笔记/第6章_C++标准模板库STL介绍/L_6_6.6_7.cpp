//对于优先队列，将重载函数卸载结构体外面，则重载的是小括号()
//并且使用第二种方式来定义优先队列
//priority_queue<fruit,vector<fruit>,cmp> q;
//即便是基本数据类型或者其他STL容器(例如set),也可以通过同样的方式定义优先级 
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
		return f1.price>f2.price;//最小的优先级高 
	}
}; 
int main()
{
	priority_queue<fruit,vector<fruit>,cmp> q;
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
/**********************************************************
如果结构体内的数据较为庞大(例如出现了字符串或者数组),建议使用引用
来提高效率

friend bool operator < (const fruit &f1,const fruit &f2){
	return f1.price>f2.price;
}

bool operator () (const fruit &f1,const fruit &f2){
	return f1.price>f2.price;
}


priority_queue可以解决一些贪心问题，也可以对Dijkstra算法进行优化
使用top()前必须用empty()判断队列是否为空
************************************************************/ 













 
