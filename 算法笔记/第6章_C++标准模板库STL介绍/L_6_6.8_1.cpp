/*****************************************************
����Ҫ������Ԫ�ذ���һ����Ϊһ���ϳ�Ԫ��ʱ,
����ʹ��pair������ṹ��
����ͷ�ļ�<utility>����<map>
���壺 
pair<typename1,typename2> name;

����ʱ����ʼ����
pair<string,int> p("hah",5);

����ʹ���Դ���make_pair����
make_pair("haha",5)

pair������Ԫ�طֱ���first��second
p.first p.second������
**************************************************/
#include<iostream>
#include<utility>
#include<string>
using namespace std;
int main()
{
	pair<string,int> p;
	p.first="haha";
	p.second=5;
	cout<<p.first<<" "<<p.second<<endl;
	p=make_pair("xixi",55);
	cout<<p.first<<" "<<p.second<<endl;
	p=pair<string,int>("hhhh",2333);
	cout<<p.first<<" "<<p.second<<endl;
	return 0;
 } 






















 
