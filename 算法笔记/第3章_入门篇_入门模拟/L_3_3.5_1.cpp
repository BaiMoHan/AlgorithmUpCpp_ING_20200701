//PAT_B1022_D���Ƶ�A+B
#include<cstdio>
int main()
{
	unsigned int a,b,d;
	scanf("%d %d %d",&a,&b,&d);
	unsigned int c=a+b;
	//��Cת��Ϊd����
	int ans[31],num=0;
	//ans��Ž��Ƶ�ÿһλ�����ڸ�����λ����ఴ�����ƿɷ�30λ
	//����ת��
	do{
		ans[num++]=c%d;
		c/=d;
	} while(c);
	//����λ����λ���
	for(int i=num-1;i>=0;i--)
		printf("%d",ans[i]);
	return 0; 
	 
 } 
