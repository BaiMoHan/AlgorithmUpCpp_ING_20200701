//PAT_B1020_�±� 
#include<stdio.h>
#include<algorithm>//����sort���� 
//�����±��Ľṹ���������Ϣ
#define N 1000
using namespace std; 
struct Mooncake{
	double store;//�ֿ�洢��
	double total;//�����ܽ��
	double price;//�±����� 
}mooncake[N]; 
bool cmp(Mooncake a,Mooncake b) //sort������cmp���� 
{
	//�����۴Ӹߵ��� 
	return a.price>b.price;
}
int main()
{
	int n,i;//�������������� 
	double sum=0,needs;//���۾����������
	//������������������
	scanf("%d %lf",&n,&needs); 
	//�����±�ÿ������Ŀ���� 
	for(i=0;i<n;i++)
	{
		scanf("%lf",&mooncake[i].store);
	 } 
	//�����±�ÿ������ȫ������Ľ��
	for(i=0;i<n;i++)
	{
		scanf("%lf",&mooncake[i].total);
	 } 
	//�����ÿ���±��ĵ��� 
	for(i=0;i<n;i++)
	{
		mooncake[i].price=mooncake[i].total/mooncake[i].store;
	}
	//�����۴Ӹߵ�������
	sort(mooncake,mooncake+n,cmp);
	//��ʼ��̰�Ĳ��Լ���������۽����۸�Ӹߵ���
	for(i=0;i<n;i++)
	{
		//���������������������������������Ե���
		if(mooncake[i].store>=needs)
		{
			sum+=mooncake[i].price*needs;
			break;//�����ټ��������� 
		 } 
		 else
		 {
		 	sum+=mooncake[i].total;//ȫ���������� 
		 	needs-=mooncake[i].store;//ʣ�಻����ȥ��һ���±����������� 
		  } 
	 } 
	 printf("������۽��Ϊ%.2f\n",sum);
	 return 0; 
 } 
