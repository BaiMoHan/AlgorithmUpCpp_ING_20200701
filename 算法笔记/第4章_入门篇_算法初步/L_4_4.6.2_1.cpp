//�ݹ�ʵ�ֹ鲢����
#include<stdio.h>
const int maxn=100;
void merge(int a[],int L1,int R1,int L2,int R2);//�������������кϲ�Ϊһ����������
void mergesort(int a[],int left,int right);//�鲢������
int main()
{
	int a[maxn]={0,5,59,23,54,16,3,28,36,86,2,9,7};
	mergesort(a,0,12) ;
	for(int i=0;i<13;i++)
		printf("%d ",a[i]);
	return 0;
 } 
void merge(int a[],int L1,int R1,int L2,int R2)
{
	//������a��[L1,R1]��[L2,R2]����ϲ�Ϊ�������䣬�˴�L2=R1+1
	int i=L1,j=L2;	//iָ��a[L1]��jָ��a[L2]
	int temp[maxn],index=0;	//��ʱ������飬����ʱָ��
	while(i<=R1 && j<=R2)
	{
		if(a[i]<a[j])		//a[i]��С 
			temp[index++]=a[i++];//��a[i]���뵽temp�� 
		else				//a[j]��С 
			temp[index++]=a[j++];//��a[j]���뵽temp�� 
	 } 
	 //��δ�ϲ��������ʣ�µ�Ԫ�ش���temp��
	 while(i<=R1)//��[L1,R1]��ʣ��Ԫ�ؼ���temp�� 
	 	temp[index++]=a[i++]; 
	 while(j<=R2)//��[L2,R2]��ʣ��Ԫ�ؼ���temp��
	 	temp[index++]=a[j++];
	 //����ʱ�����ֵ���¸�ֵ��ԭ����
	 for(i=0;i<index;i++)
	 	a[L1+i]=temp[i]; //ע��˴�����a�Ǵ�a[L1]��ʼ�ģ�����a[0] 
} 
void mergesort(int a[],int left,int right)
{
	//��a����[left,right]������й鲢����
	int mid;	//ȡ�����е�
	if(left<right)//��left==right��ʱ��˵��ֻʣһ��Ԫ���� 
	{
		mid=left+(right-left)/2;	//�������
		mergesort(a,left,mid);//�ݹ飬��[left,right]����鲢����
		mergesort(a,mid+1,right);//�ݹ飬��[mid+1,right]����鲢����
		merge(a,left,mid,mid+1,right);//���������������ϲ� 
	}
	 
}
