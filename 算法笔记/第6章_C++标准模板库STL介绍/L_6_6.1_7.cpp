//insert(it,x)������vector�����������it������һ��Ԫ��x��ʱ�临�Ӷ�O��N��
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	vector<int> vi;
	for(int i=1;i<=33;i++){
		vi.push_back(i);
	}
	vi.insert(vi.begin()+2,-1);//��-1���뵽vi[2] 
	for(int i=0;i<vi.size();i++)
		printf("%d ",vi[i]);
	return 0;
 } 
