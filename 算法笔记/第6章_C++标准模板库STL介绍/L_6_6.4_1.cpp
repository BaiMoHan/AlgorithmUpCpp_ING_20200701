/***************************************************
map映射，可以将任何基本类型（包括STL容器）映射到任何
基本类型（包括STL容器）
map<typename1,typename2> mp; 
map<string,int> mp; //字符串到整型的映射 
将python里面的dic字典键值对 对比起来理解 

****************************************************/ 
//通过下标访问，map中的键是唯一的
#include<stdio.h>
#include<map>
using namespace std;
int main(){
	map<char,int> mp;
	mp['c']=20;
	mp['c']=30;
	printf("%d\n",mp['c']);
	return 0;
} 
