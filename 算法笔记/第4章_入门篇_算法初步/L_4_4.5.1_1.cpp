#include<stdio.h>
int binarysearch(int a[],int left,int right,int x);
int main()
{
	const int n=10;
	int a[n]={1,2,3,4,5,8,34,49,90,190};//�˴�Ϊ�ϸ�������� 
	//��˳����в���6��9 
	printf("%d %d",binarysearch(a,0,n-1,49),binarysearch(a,0,n-1,9));
	return 0; 
}

//�����������������˳�����˵㣬�Ҷ˵㣬�����ҵ�Ԫ�� 
int binarysearch(int a[],int left,int right,int x)
{
	int mid;//��λ�� 
	while(left<=right)//�Ƴ�����Ϊleft>right 
	{
		//ÿһ�β��Ҷ��ӵ�ǰ������м䴦��ʼ 
		mid=left+(right-left)/2;//�����Ա�̣���ֹleft+right���int�����
		if(a[mid]==x)
			return mid;//�ҵ�x�������±�
		else if(a[mid]>x)//�������дӴ��ڿ�ʼ
			right=mid-1;//�м�λ�ô��ڴ���ֵ��˵��������������е�����
		else
			left=mid+1;//˵��������ڣ�����������ұ� 
	}
	return -1;//�����˳�ѭ��˵��û�ҵ� 
}
