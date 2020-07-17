//erase(first,last),删除[first,last)内的所有元素,外国人经常是左闭右开
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	vector<int> vi;
	for(int i=5;i<=9;i++)
		vi.push_back(i);
	vi.erase(vi.begin()+1,vi.begin()+4);//删除vi[1],vi[2],vi[3]
	for(int i=0;i<vi.size();i++)
		printf("%d ",vi[i]);
	return 0; 
 } 
