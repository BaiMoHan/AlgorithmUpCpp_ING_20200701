//̰�����������
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=110;
struct Inteval{
	int x;
	int y;
}inteval[maxn];
bool cmp(struct Inteval a,struct Inteval b)
{
	//�Ȱ�����˵�Ӵ�С����
	if(a.x!=b.x)
		return a.x>b.x;
	//�ٰ����Ҷ˵��С��������Ϊ���ڳ�����Ŀռ� 
	else
		return a.y<b.y; 
		 
 } 
 int main()
 {
 	int n,i,count=1,lastx;
 	while(scanf("%d",&n),n!=0)//��Զ����������� 
 	{
 		//����������Ϣ
		 for(i=0;i<n;i++)
		 	scanf("%d %d",&inteval[i].x,&inteval[i].y);
		//�������������
		sort(inteval,inteval+n,cmp);
		lastx=inteval[0].x;//��ʼ��ȡ��һ���������˵�
		for(i=1;i<n;i++)
		{
			if(inteval[i].y<=lastx)//�����������Ҷϵ����һ���������˵㺣Х
			{
				//����������޽���
				lastx=inteval[i].x;
				count++; 
			 } 
		 } 
		 printf("����๹��%d������û�н���������\n",count);
	 }
	 return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
