//PAT_A1025_PAT Ranking 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Student{
	char id[15];//׼��֤��
	int score;//����
	int location_number;//׼��֤��
	int local_rank;//���������� 
}stu[30010];
bool cmp(Student a,Student b){
	if(a.score!=b.score) return a.score>b.score;//�Ȱ��շ����Ӹߵ���
	else return strcmp(a.id,b.id)<0;//������ͬ����׼��֤�Ŵ�С�������� 
}
int main(){
	int n,k,num=0;//numΪ�ܿ�����
	scanf("%d",&n);//nΪ������
	for(int i=1;i<=n;i++){
		scanf("%d",&k);//��ȡ�����ڵ�ѧ������
		for(int j=0;j<k;j++){
			scanf("%s %d",stu[num].id,&stu[num].score);//��ȡѧ����Ϣ
			stu[num].location_number=i;//�ÿ����Ŀ�����Ϊi
			num++;//������������ 
		} 
		//����һ�������ڵ���Ϣ�󣬽�������,����<algorithm>�ڵ�sort����
		sort(stu+num-k,stu+num,cmp);
		stu[num-k].local_rank=1;//���ÿ����ĵ�һ����Ϊ1
		//����Կ���ʣ���ѧ����������
		for(int j=num-k+1;j<num;j++)
		{
			if(stu[j].score==stu[j-1].score)//�����ǰ������ǰһλ����ͬ��
				//������local_rankҲ��ͬ
				stu[j].local_rank=stu[j-1].local_rank;
			else
				stu[j].local_rank=j+1-(num-k);//����ͷ������,���������0��ʼ������Ϊ�±�+1 
		 } 
	}
	printf("%d\n",num);//����ܿ�����
	sort(stu,stu+num,cmp);//���ܿ�����������
	int r=1;//��ǰ����������
	for(int i=0;i<num;i++){
		if(i>0 && stu[i].score!=stu[i-1].score)
			r=i+1;//��ǰ��������һ������������ͬʱ��r����Ϊ����+1
		printf("%s ",stu[i].id);//���������id
		printf("%d %d %d\n",r,stu[i].location_number,stu[i].local_rank);
	}
	return 0;
}
