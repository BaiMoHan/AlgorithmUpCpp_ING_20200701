//codeup_1928_日期差值
#include<cstdio>
int month[13][2]={
{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},
{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}
};
bool isLeap(int year)//判断是否是闰年
{
	return (!year%4 && year%100 || !year%400); 
 } 
 int main()
 {
 	int time1,y1,m1,d1;
 	int time2,y2,m2,d2;
 	while(scanf("%d%d",&time1,&time2)!=EOF)
 	{
 		//为方便，time1<time2
		if(time1>time2)
		{
			//第一个日期晚于第二个日期，则交换
			int temp=time1;
			time1=time2;
			time2=temp; 
		}
		y1=time1/10000,m1=time1%10000/100,d1=time1%100;
		y2=time2/10000,m2=time2%10000/100,d2=time2%100;
		int ans=1;//记录结果
		//第一个日期没有到达第二个日期时进行循环
		while(y1*10000+m1*100+d1<y2*10000+m2*100+d2)
		{
			d1++;//天数自增
			if(d1>=month[m1][isLeap(y1)]+1)
			{
				//天数为当月最大天数+1时考虑进入下一个月
				m1++;//月份自增 
				d1=1;//天数从第一天算起 
			 } 
			 if(m1==13)
			 {
			 	//月份超过12个月时， 
			 	y1++;//年份自增 
			 	m1=1;//月份从1月再开始算 
			 }
			 ans++;//累计 
		}
		printf("%d\n",ans); 
	 }
	 return 0;
 }

