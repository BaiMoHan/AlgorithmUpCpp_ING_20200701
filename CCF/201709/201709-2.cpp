#include<iostream>
#include<algorithm>
#define _rep(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define OJ 98
using namespace std;
#define N 1003
struct node{
	int num;//Կ�ױ��
	int t;	//����ʱ�� 
}p1[N],p2[N];//p1ΪȡԿ�ף�p2Ϊ��Կ��
int key[N];	//Կ�� 
bool cmp(struct node a,struct node b)
{
	//������ʱ���С�������� 
	if(a.t<b.t)
		return true;
	//����ʱ����ͬ�Ͱ�����Ŵ�С�������� 
	else if(a.t==b.t)
		return a.num<b.num;
	else
		return false;
}
int main()
{
	#ifndef OJ
	freopen("201709-2.txt","r",stdin);
	#endif
	int n,k;
	cin>>n>>k;
	int w,s,c;
	_rep(i,1,n)
		key[i]=i;
	_rep(i,1,k)
	{
		cin>>w>>s>>c;
		//ȡ 
		p1[i].num=w;
		p1[i].t=s;
		//�� 
		p2[i].num=w;
		p2[i].t=s+c;
	 } 
	//��p1 p2���� 
	sort(p1+1,p1+1+k,cmp);
	sort(p2+1,p2+1+k,cmp);
	
	int i=1,j=1;
	while(i!=k+1&&j!=k+1)
	{
		//ȡ��һ�𣬻��߻���ʱ����ǰ�������Ȼ� 
		if(p1[i].t>=p2[j].t)
		{
			//�Ȼ�
			_rep(z,1,n)
				if(key[z]==0)
				{
					key[z]=p2[j].num;
					j++;//�Ƶ�����һ��p2
					break;
				} 
		 }else	//��ȡ 
		 {
		 	_rep(z,1,n)
		 		if(key[z]==p1[i].num)
		 		{
		 			key[z]=0;
		 			i++;	//�Ƶ���һ�� 
		 			break;
				 }
		 }
	}
	
	//���ʣ�µĿ϶���û�л���
	while(j<=k)
	{
		_rep(z,1,n)
		if(key[z]==0)
		{
			key[z]=p2[j].num;
			j++;//�Ƶ�����һ��p2
			break;
		} 
	 } 
	
	_rep(z,1,n-1)
		cout<<key[z]<<" ";
	cout<<key[n];
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
