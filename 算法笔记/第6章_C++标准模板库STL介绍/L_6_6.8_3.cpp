//pair������������;
//1.���������Ԫ�ṹ�弰�乹�캯��,���Խ�ʡ����ʱ��
//2.��Ϊmap�ļ�ֵ�������в���
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	map<string,int> mp;
	mp.insert(make_pair("heihei",5));
	mp.insert(pair<string,int>("haha",66));
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
		cout<<it->first<<" "<<it->second<<endl;
	return 0;
 } 
