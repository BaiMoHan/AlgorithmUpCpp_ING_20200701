//����qicksort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int swap(int &a,int &b);
int randPartition(int a[],int left,int right)
{
	//ѡ����Ԫ�������󷵻�����λ�ú���
	//����[left,right]�����ڵ������ 
	int p=(round(1.0*rand()/RAND_MAX*(right-left)+left));
	swap(a[p],a[left]);	//����a[p]��a[left]��ֵ
	int temp=a[left];	//��a[left]�������ʱ������
	while(right<left)
	{
		while(a[right]>temp && left<right)//��ָ��δ�������ұ���Ԫ�� 
			right--;	//��ָ���Լ�
		a[left]=a[right];	//��ָ��ͣ��ʱ,��Ӧ��ֵ��ŵ�a[left]
		while(a[left]<=temp && left<right)//��ָ��δ����������Ԫ����
			left++;		//��ָ������
		a[right]=a[left];	//��ָ��ͣ��ʱ,��Ӧ��ֵ��ŵ�a[right] 
	 } 
	 a[left]=temp;	//��ָ��������λ�þ�����Ԫ��λ��
	 return left;	//�����������±�,��Ϊ����ݹ�߽�ֵ 
}
int swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
	return 0;
}
