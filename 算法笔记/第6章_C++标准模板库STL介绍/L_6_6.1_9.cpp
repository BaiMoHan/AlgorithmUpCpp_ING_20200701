//erase(first,last),ɾ��[first,last)�ڵ�����Ԫ��,����˾���������ҿ�
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	vector<int> vi;
	for(int i=5;i<=9;i++)
		vi.push_back(i);
	vi.erase(vi.begin()+1,vi.begin()+4);//ɾ��vi[1],vi[2],vi[3]
	for(int i=0;i<vi.size();i++)
		printf("%d ",vi[i]);
	return 0; 
 } 
