#include<iostream>
using namespace std;
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define N 1004
struct tree{
	int num;	//������Ŀ
	int flag;	//����Ƿ�����ӣ�1��ʾ���� 
	tree(){
		num=0;
		flag=0;
	} 
}node[N]; 
int main()
{
	#ifndef OJ
	freopen("201909-2.txt","r",stdin);
	#endif
	int n;	//�������� 
	cin>>n;
	int k;	//ÿ�����Ĳ������� 
	int D=0;//���������Ŀ
	int E=0;//�������õ�������� 
	long T=0;//ʣ�µĹ�����Ŀ 
	int temp=0;
	bool count=false;	//����Ƿ��Ѿ�ͳ�ƹ����� 
	//��ȡ���ж� 
	_rep(i,0,n)
	{
		//��ȡ�������� 
		cin>>k;
		//��ȡ�����ĳ�ʼ������Ŀ 
		cin>>node[i].num;
		_rep(j,1,k)
		{
			//��ȡ��ֵ 
			cin>>temp;
			//����0˵��û����� 
			if(temp>0){	//�ж��Ƿ������
				if(node[i].num>temp) 
				{
					node[i].flag=1;
					if(count==false)
					{
						D++;	//����Ĺ�����Ŀ���� 
						count=true;
					}
				}
				node[i].num=temp;
			}else{
				node[i].num+=temp;	//��� 
			}
		}
		count=false;	//�ָ�ͳ�Ʊ�־ 
	}
	//ͳ��T��E
	_rep(i,0,n)
	{
		T+=node[i].num;
		//�ж��������ڵ������� 
		if(node[(i+n-1)%n].flag&&node[(i+1)%n].flag&&node[i].flag&&n>2)
			E++;
	 } 
	cout<<T<<" "<<D<<" "<<E;

	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
