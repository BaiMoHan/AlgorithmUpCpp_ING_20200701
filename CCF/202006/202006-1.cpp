#include<iostream>
#include<cstdio>
#define OJ 98
#define N 1002 
using namespace std;
int x[N],y[N];//��� 
char type[N];//������� 
int main()
{
	#ifndef OJ
	freopen("202006-1.txt","r",stdin);
	#endif
	int n;//n���� 
	int m;//m�����Է��� 
	int t1,t2,t3;//t1����,t2Ϊxϵ��,t3Ϊy��ϵ�� 
	cin>>n>>m;//��ȡn m 
	bool ABREAK=false;	//A���Ƿ���ǰ��ֹ 
	bool BBREAK=false;	//B���Ƿ���ǰ��ֹ
	bool AFIRST=false;	//A���Ƿ��Ѿ���һ��ȷ��
	bool BFIRST=false;	//B���Ƿ��Ѿ���һ��ȷ��
	bool ASTATE,BSTATE;	//A���B��Ķ��ڷ��̵�״̬ 

	//��ȡn����Ե���Ϣ 
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i]>>type[i];
	}
	//��ȡ�б𷽳̲��ж� 
	for(int j=0;j<m;j++)
	{
		cin>>t1>>t2>>t3;
		for(int i=0;i<n;i++)
		{
			if(type[i]=='A')
			{
				if(AFIRST==false)//��ʱASTATE��δȷ�� 
				{
					AFIRST=true;
					ASTATE=(t1+t2*x[i]+t3*y[i]<0);//��һ������ȷ��ASTATE����Ƿ�С��0 
				}
				else{
					if(ASTATE!=(t1+t2*x[i]+t3*y[i]<0))//A���״̬��ͻ�� 
					{
						printf("No\n");//����ѭ������ǰ�жϽ��� 
						ABREAK=true;
						break;
					}
				}
			}
			else{
				if(BFIRST==false)
				{
					BFIRST=true;
					BSTATE=(t1+t2*x[i]+t3*y[i]>0);
				}
				else{
					if(BSTATE!=(t1+t2*x[i]+t3*y[i]>0))
					{
						printf("No\n");
						BBREAK=true;
						break;
					}
				}
			}
		}
		if(BBREAK!=true&&ABREAK!=true&&ASTATE==BSTATE)
		{
			printf("Yes\n");
		}
		//ÿ��ѭ���������ʼ��bool����
		AFIRST=false;
		BFIRST=false;
		BBREAK=false;
		ABREAK=false;	
	}
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
