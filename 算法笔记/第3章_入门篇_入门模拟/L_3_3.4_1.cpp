//codeup_1928_���ڲ�ֵ
#include<cstdio>
int month[13][2]={
{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},
{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}
};
bool isLeap(int year)//�ж��Ƿ�������
{
	return (!year%4 && year%100 || !year%400); 
 } 
 int main()
 {
 	int time1,y1,m1,d1;
 	int time2,y2,m2,d2;
 	while(scanf("%d%d",&time1,&time2)!=EOF)
 	{
 		//Ϊ���㣬time1<time2
		if(time1>time2)
		{
			//��һ���������ڵڶ������ڣ��򽻻�
			int temp=time1;
			time1=time2;
			time2=temp; 
		}
		y1=time1/10000,m1=time1%10000/100,d1=time1%100;
		y2=time2/10000,m2=time2%10000/100,d2=time2%100;
		int ans=1;//��¼���
		//��һ������û�е���ڶ�������ʱ����ѭ��
		while(y1*10000+m1*100+d1<y2*10000+m2*100+d2)
		{
			d1++;//��������
			if(d1>=month[m1][isLeap(y1)]+1)
			{
				//����Ϊ�����������+1ʱ���ǽ�����һ����
				m1++;//�·����� 
				d1=1;//�����ӵ�һ������ 
			 } 
			 if(m1==13)
			 {
			 	//�·ݳ���12����ʱ�� 
			 	y1++;//������� 
			 	m1=1;//�·ݴ�1���ٿ�ʼ�� 
			 }
			 ans++;//�ۼ� 
		}
		printf("%d\n",ans); 
	 }
	 return 0;
 }

