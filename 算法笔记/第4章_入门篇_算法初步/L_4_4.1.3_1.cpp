//PAT_A1025_PAT Ranking 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Student{
	char id[15];//准考证号
	int score;//分数
	int location_number;//准考证号
	int local_rank;//考场内排名 
}stu[30010];
bool cmp(Student a,Student b){
	if(a.score!=b.score) return a.score>b.score;//先按照分数从高到低
	else return strcmp(a.id,b.id)<0;//分数相同按照准考证号从小到大排序 
}
int main(){
	int n,k,num=0;//num为总考生数
	scanf("%d",&n);//n为考场数
	for(int i=1;i<=n;i++){
		scanf("%d",&k);//读取考场内的学生人数
		for(int j=0;j<k;j++){
			scanf("%s %d",stu[num].id,&stu[num].score);//读取学生信息
			stu[num].location_number=i;//该考生的考场号为i
			num++;//考生人数自增 
		} 
		//读完一个考场内的信息后，进行排序,调用<algorithm>内的sort函数
		sort(stu+num-k,stu+num,cmp);
		stu[num-k].local_rank=1;//将该考场的第一名记为1
		//下面对考场剩余的学生进行排名
		for(int j=num-k+1;j<num;j++)
		{
			if(stu[j].score==stu[j-1].score)//如果当前考生与前一位考生同分
				//则排名local_rank也相同
				stu[j].local_rank=stu[j-1].local_rank;
			else
				stu[j].local_rank=j+1-(num-k);//按人头数排名,数组如果从0开始，排名为下标+1 
		 } 
	}
	printf("%d\n",num);//输出总考生数
	sort(stu,stu+num,cmp);//对总考生进行排序
	int r=1;//当前考生的排名
	for(int i=0;i<num;i++){
		if(i>0 && stu[i].score!=stu[i-1].score)
			r=i+1;//当前考生与上一名考生分数不同时，r更新为人数+1
		printf("%s ",stu[i].id);//输出考生的id
		printf("%d %d %d\n",r,stu[i].location_number,stu[i].local_rank);
	}
	return 0;
}
