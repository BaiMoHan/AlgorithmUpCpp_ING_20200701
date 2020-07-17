//clear一次清空vector中所有元素,时间复杂度O（N） 
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	vector<int> vi;
	for(int i=1;i<=33;i++){
		vi.push_back(i);
	}
	vi.clear(); 
	printf("%d ",vi.size());
	return 0;
 } 
