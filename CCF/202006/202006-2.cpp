#include<iostream>
#include<vector>
#include<utility>
#define OJ 98
#define _rep(i,a,b) for(int i=(a);i<(b);++i) //ѭ���궨��
using namespace std; 
int main()
{
	#ifndef OJ
	freopen("202006-2.txt","r",stdin);
	#endif
	vector<pair<int,int> > v;
	int n;	//ά��
	int a;	//��һ�������ĸ���
	int b;	//�ڶ��������ĸ��� 
	long long res=0;
	cin>>n>>a>>b;
	
	int index,value;//�м���� 
	_rep(i,0,a)	//�����һ��ϡ������ 
	{
		cin>>index>>value;
		v.push_back(make_pair(index,value));
	}
	int j=0;
	_rep(i,0,b)//��ȡ�ڶ���ϡ���������ж� 
	{
		cin>>index>>value;
		while(j<a)
		{
			if(index>v[j].first)	//��һ��������indexС�ˣ���һ�������Ƶ���һ�� 
				j++;
			else if(index<v[j].first)	//��һ��������index���ˣ� �ڶ��������Ƶ�
				break;
			else	//�պö���λ��
			{
				res+=value*v[j].second;
				j++;
			} 
		}	
	}
	cout<<res<<endl;
	
	#ifndef	OJ
	fclose(stdin);
	#endif
}
