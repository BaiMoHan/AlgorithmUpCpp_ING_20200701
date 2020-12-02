#include<iostream>
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define N 1004
#include<vector>
#include<algorithm>
using namespace std; 
struct Node1{
	int x;
	int y;
	int count;
}node[N];
vector<int> book; 
int score0;
int score1;
int score2;
int score3;
int score4;

int main()
{
	#ifndef OJ
	freopen("201912-2.txt","r",stdin);
	#endif
	
	
	int n;	//�������
	cin>>n;
	_rep(i,0,n)	//��ȡ 
	{
		cin>>node[i].x>>node[i].y;
		node[i].count=0;
	}
	//����������,ͳ�����������Ƿ��е� 
	int tx=0,ty=0;
	_rep(i,0,n)
	{
		tx=node[i].x;
		ty=node[i].y;
		_rep(j,0,n)
		{
			if(i==j)
				continue;
			//��
			if(node[j].x==tx&&node[j].y==ty+1)
				node[i].count++;
			//�� 
			if(node[j].x==tx&&node[j].y==ty-1)
				node[i].count++;
			//�� 
			if(node[j].x==tx-1&&node[j].y==ty)
				node[i].count++;
			//�� 
			if(node[j].x==tx+1&&node[j].y==ty)
				node[i].count++;
			if(node[i].count==4)	//�ҵ�����վ��ַ����¼ 
			{
				book.push_back(i);
				break;
			}
		}
	 } 
	 
	 
	 //���ÿ������վ�ķ��� 
	 int score=0;
	_rep(i,0,book.size())
	{
		tx=node[book[i]].x;
		ty=node[book[i]].y;
		_rep(j,0,n)
		{
			if(j==book[i])	//ɨ�赽�Լ�
				continue; 
			//����
			if(node[j].x==tx-1&&node[j].y==ty+1)
				score++;
			//����
			if(node[j].x==tx+1&&node[j].y==ty+1)
				score++;
			//���� 
			if(node[j].x==tx-1&&node[j].y==ty-1)
				score++;
			//���� 
			if(node[j].x==tx+1&&node[j].y==ty-1)
				score++;
		 } 
		switch(score){
			case 0:score0++;break;
			case 1:score1++;break;
			case 2:score2++;break;
			case 3:score3++;break;
			case 4:score4++;break;
			default:cout<<score<<endl;break;
		}
		score=0;
	}
	cout<<score0<<endl;
	cout<<score1<<endl;
	cout<<score2<<endl;
	cout<<score3<<endl;
	cout<<score4<<endl;
	
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
