//erase(it)��ɾ��������it����Ԫ��,ʱ�临�Ӷ�O��N��
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	vector<int> vi;
	for(int i=5;i<=9;i++)
		vi.push_back(i);
	
	vi.erase(vi.begin()+2);//ɾ��vi[2],��������Ԫ��7
	for(int i=0;i<vi.size();i++)
		printf("%d ",vi[i]);
	return 0; 
 } 
