//clearһ�����vector������Ԫ��,ʱ�临�Ӷ�O��N�� 
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
