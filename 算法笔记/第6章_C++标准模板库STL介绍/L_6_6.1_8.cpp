//erase(it)，删除迭代器it处的元素,时间复杂度O（N）
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	vector<int> vi;
	for(int i=5;i<=9;i++)
		vi.push_back(i);
	
	vi.erase(vi.begin()+2);//删除vi[2],即第三个元素7
	for(int i=0;i<vi.size();i++)
		printf("%d ",vi[i]);
	return 0; 
 } 
