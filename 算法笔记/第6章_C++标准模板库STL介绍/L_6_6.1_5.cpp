//��ȡvector��Ԫ�ظ���,size(),ʱ�临�Ӷ�O��1�� 
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
