//vector�����÷�,�䳤���� 
/*****************************************************
vector<int> name;
vector<char> name;
vector<double> name;
vector<node> name;//node�ǽṹ������

ͨ������������
vector<int>::iterator it;//*it�õ�Ԫ�� 
********************************************************/ 
#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	vector<int> vi;
	for(int i=1;i<=5;i++){
		vi.push_back(i);
	}
	//vi.begin()Ϊ��Ԫ�ص�ַ,itָ�������ַ
	vector<int>::iterator it=vi.begin();
	for(int i=0;i<5;i++){
		printf("%d ",*(it+i));//ֻ��vector �� string����ʹ��*(it+i)������ȡԪ����ʽ 
	} 
	return 0;
}
