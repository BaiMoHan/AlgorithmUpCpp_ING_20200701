//vector常见用法,变长数组 
/*****************************************************
vector<int> name;
vector<char> name;
vector<double> name;
vector<node> name;//node是结构体类型

通过迭代器访问
vector<int>::iterator it;//*it得到元素 
********************************************************/ 
#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	vector<int> vi;
	for(int i=1;i<=5;i++){
		vi.push_back(i);
	}
	//vi.begin()为首元素地址,it指向这个地址
	vector<int>::iterator it=vi.begin();
	for(int i=0;i<5;i++){
		printf("%d ",*(it+i));//只有vector 和 string才能使用*(it+i)这样的取元素形式 
	} 
	return 0;
}
