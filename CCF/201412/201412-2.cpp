#include<iostream>
using namespace std;
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define N 503
#define E 0	//��
#define WS 1	//������
#define S 2	//����
#define EN 3	//�򶫱� 
int mp[N][N];
struct node{
	int row;
	int rol;
}dic[4]={{0,1},{1,-1},{1,0},{-1,1}};//�ĸ������λ�ñ任 
int main()
{
	#ifndef OJ
	freopen("201412-2.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	_rep(i,0,n)
		_rep(j,0,n)
			cin>>mp[i][j];
	bool flag=false;
	int i=0,j=0;
	int num=0;
	int state=0;	//һ��ʼ����
	cout<<mp[0][0]; 
	while(i!=n-1||j!=n-1)
	{
		i+=dic[state].row;
		j+=dic[state].rol;
		cout<<" "<<mp[i][j];
		
		//���ݵ�ǰ��state��λ���ж���һ��state
		if(state==E&&i==0){	//ֻ���ڵ�һ���򶫲������� 
			state=WS;	//��һ�������� 
		}else if(state==E&&i==n-1){	//���һ���򶫺��򶫱� 
			//�򶫵����ұ߽�
			state=EN;	//��һ���򶫱� 
		}else if(state==S&&j==0){
			//����߽����ϣ�����û�е����±߽�
			state=EN;	//�򶫱� 
		}else if(state==S&&j==n-1){
			//���ұ߽�����,����û�е������һ��
			//������
			state=WS; 
		}else if(state==WS&&i==n-1){//�����ϵ����ұ߽������Ϸ������±߽� 
			state=E;	//��һ���� 
		}else if(state==WS&&j==0){
			//���Ϸ�������߽� 
			state=S;	//�������� 
		}else if(state==EN&&j==n-1){
			//���������ұ߽� 
			state=S;	//���� 
		}else if(state==EN&&i==0){
			//�������ϱ߽�
			state=E;//�� 
		}
	}
	
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
 
