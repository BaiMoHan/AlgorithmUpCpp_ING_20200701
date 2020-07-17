#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	vector<int> vi;
	for(int i=1;i<=5;i++){
		vi.push_back(i);
	}
	//vector的迭代器不支持it<vi.end()的写法,只能写it!=vi.end()
	for(vector<int>::iterator it=vi.begin();it!=vi.end();it++){
		printf("%d ",*it);
	}
	return 0;
} 
