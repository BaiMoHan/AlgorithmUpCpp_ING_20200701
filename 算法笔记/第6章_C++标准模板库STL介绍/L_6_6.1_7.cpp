//insert(it,x)用来向vector的任意迭代器it处插入一个元素x，时间复杂度O（N）
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	vector<int> vi;
	for(int i=1;i<=33;i++){
		vi.push_back(i);
	}
	vi.insert(vi.begin()+2,-1);//将-1插入到vi[2] 
	for(int i=0;i<vi.size();i++)
		printf("%d ",vi[i]);
	return 0;
 } 
