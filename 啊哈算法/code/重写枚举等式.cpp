#include<stdio.h>
int a[10],book[100],total;
void deep_first_search(int step);
int main()
{
	deep_first_search(1);//�ȴӵ�һ�����ӿ�ʼ
	
	printf("�ܹ������%d�ֿ�����ĵ�ʽ",total/2);
	return 0; 
}
void deep_first_search(int step)
{
	int x,y,z,i; 
	if(step==10)//����ǰ��9�������Ѿ����ú�
	{
		//�ж��ܷ���ɵ�ʽ 
		x=a[1]*100+a[2]*10+a[3];
		y=a[4]*100+a[5]*10+a[6];
		z=a[7]*100+a[8]*10+a[9];
		if(x+y==z)
		{
			total++;
			printf("%d+%d=%d\n",x,y,z);
		 } 
		 return ;//������һ�����øú����ĵط� 
	 } 
	 for(i=1;i<=9;i++)
	 {
	 	if(book[i]==0)//�ж��Ƿ���Դ���� 
	 	{
	 		a[step]=i;//��������� 
			book[i]=1;//������Ӻ�Ҫ���
			
			deep_first_search(step+1);//��һ����������һ����ͬ 
			book[i]=0;// �����ջأ���ʼ��һ�γ��� 
		 }
	 }
	 return ; 
}
