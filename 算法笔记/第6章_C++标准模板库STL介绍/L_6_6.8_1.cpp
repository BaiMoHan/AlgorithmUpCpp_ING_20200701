/*****************************************************
当想要将两个元素绑在一起作为一个合成元素时,
可以使用pair来代替结构体
包含头文件<utility>或者<map>
定义： 
pair<typename1,typename2> name;

定义时并初始化：
pair<string,int> p("hah",5);

或者使用自带的make_pair函数
make_pair("haha",5)

pair中两个元素分别是first和second
p.first p.second来访问
**************************************************/
#include<iostream>
#include<utility>
#include<string>
using namespace std;
int main()
{
	pair<string,int> p;
	p.first="haha";
	p.second=5;
	cout<<p.first<<" "<<p.second<<endl;
	p=make_pair("xixi",55);
	cout<<p.first<<" "<<p.second<<endl;
	p=pair<string,int>("hhhh",2333);
	cout<<p.first<<" "<<p.second<<endl;
	return 0;
 } 






















 
