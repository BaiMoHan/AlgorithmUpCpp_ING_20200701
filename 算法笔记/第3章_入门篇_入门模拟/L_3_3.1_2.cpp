//PAT_B_1032_挖掘机技术哪家强
#include<cstdio>
#define max 100001//确定最大值
int school[max];//用来存放学校的总分数，全局变量默认为0
int main()
{
	int N,num,score,MAX,i;
	//读取接下来输入N组数 
	scanf("%d",&N);
	//统计各个学校的分数 
	for(i=1;i<=N;i++)
	{
		//读取学校编号和成绩 
		scanf("%d %d",&num,&score);
		//累加成绩
		school[num]+=score;
	 } 
	 //统计完所有学校成绩后，使用擂台法输出最大的成绩
	  num=1;MAX=school[1];
	  for(i=1;i<=N;i++)
	  {
	  	if(school[i]>MAX)
	  	{
	  		num=i;
	  		MAX=school[num];
		  }
	  }
	  //输出最大的学校
	  printf("%d %d",num,school[num]);
	  return 0; 
 } 
