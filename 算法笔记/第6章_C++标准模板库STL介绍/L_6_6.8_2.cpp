//pair类型可以直接使用比较运算符,先比较first,first相等再比较second
#include<cstdio>
#include<utility>
using namespace std;
int main()
{
	pair<int,int> p1(5,10);
	pair<int,int> p2(5,15);
	pair<int,int> p3(10,5);
	if(p1<p3)
		printf("p1<p3\n");
	if(p1<=p3)
		printf("p1<=p3\n");
	if(p1<p2)
		printf("p1<p2\n");
	return 0; 
	
 } 
