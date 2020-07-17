//获取vector中元素个数,size(),时间复杂度O（1） 
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	vector<int> vi;
	for(int i=1;i<=33;i++){
		vi.push_back(i);
	}
	printf("%d ",vi.size());
	vi.pop_back();
	printf("%d ",vi.size());
	return 0;
 } 
