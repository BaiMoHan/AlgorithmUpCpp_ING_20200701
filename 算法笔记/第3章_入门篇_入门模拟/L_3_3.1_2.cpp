//PAT_B_1032_�ھ�������ļ�ǿ
#include<cstdio>
#define max 100001//ȷ�����ֵ
int school[max];//�������ѧУ���ܷ�����ȫ�ֱ���Ĭ��Ϊ0
int main()
{
	int N,num,score,MAX,i;
	//��ȡ����������N���� 
	scanf("%d",&N);
	//ͳ�Ƹ���ѧУ�ķ��� 
	for(i=1;i<=N;i++)
	{
		//��ȡѧУ��źͳɼ� 
		scanf("%d %d",&num,&score);
		//�ۼӳɼ�
		school[num]+=score;
	 } 
	 //ͳ��������ѧУ�ɼ���ʹ����̨��������ĳɼ�
	  num=1;MAX=school[1];
	  for(i=1;i<=N;i++)
	  {
	  	if(school[i]>MAX)
	  	{
	  		num=i;
	  		MAX=school[num];
		  }
	  }
	  //�������ѧУ
	  printf("%d %d",num,school[num]);
	  return 0; 
 } 
