/***************************************************
mapӳ�䣬���Խ��κλ������ͣ�����STL������ӳ�䵽�κ�
�������ͣ�����STL������
map<typename1,typename2> mp; 
map<string,int> mp; //�ַ��������͵�ӳ�� 
��python�����dic�ֵ��ֵ�� �Ա�������� 

****************************************************/ 
//ͨ���±���ʣ�map�еļ���Ψһ��
#include<stdio.h>
#include<map>
using namespace std;
int main(){
	map<char,int> mp;
	mp['c']=20;
	mp['c']=30;
	printf("%d\n",mp['c']);
	return 0;
} 
