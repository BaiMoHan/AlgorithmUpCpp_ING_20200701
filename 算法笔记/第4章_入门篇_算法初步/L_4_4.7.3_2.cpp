//��һ���������ϻ���Ϊ�����Ӽ�,Ҫ��Ԫ�ظ���֮�����ֵ��С,������Ԫ�غ�֮��ľ���ֵ��С
//�õ����ѡ���㷨��ǰK���Ԫ�ط�һ���Ӽ���ʣ�µķŵ���һ���Ӽ�
//�ȿ���Ҫ�죬����Ϊ���Խ�ʱ�临�Ӷ�
#include<cstdio>
#include<cstdlib>
#include<math.h>//�õ�ֻ�����������ֵĺ���round
#include<ctime> //����ʱ������ʼ�����������
#include<algorithm>	//STL�㷨
using namespace std;
const int maxn=10010;//���ϵ���Ԫ�������Ŀ 
int A[maxn],n;	//A����������������nΪԪ�صĸ���
int randPartition(int A[],int left,int right);	//���ѡ����Ԫ���ֺ���
void randSelect(int A[],int left,int right,int K);//���ѡ���K����㷨����
int main()
{
	srand((unsigned) time(NULL));//��ʼ�����������
	int sum=0,sum1=0;//sumΪ��Ԫ��֮��,sum1Ϊ�зֺ�ǰn/2��Ԫ��֮��
	scanf("%d",&n);		//��ȡ��Ԫ�صĸ���
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);//��Ԫ�����ζ��뵽������
		sum+=A[i];	//�ۼ���Ԫ�غ� 
	 } 
	randSelect(A,0,n,n/2);	//�ҵ�n/2���Ԫ��,���л���
	for(int i=0;i<n/2;i++)	//���ǰn/2���ۼӺ�,�����ֺ�����һ���Ӽ���Ԫ�غ�
		sum1+=A[i];			//Ԫ�������ۼ�
	printf("�����ϵ�Ԫ��֮��Ϊ%d",sum-(sum-sum1));
	return 0; 
 } 
int randPartition(int A[],int left,int right)
{
	//����[left,right]֮��������p
	int p=(round(1.0*rand()/RAND_MAX*(right-left)+left));
	swap(A[p],A[left]);	//��A[p]��A[left]����,swap������<algorithm>������
	//����Ϊԭ��ѡ��a[left]Ϊ��Ԫ�ĺ���Paritition����
	int temp=A[left];	//��A[left]�������ʱ������
	while(left<right)	//��left��rightС��ʱ��Ϳ�ʼ�����Ƚ�Ԫ��
	{
		//�ȴ�Զ��շ��ӵ�һ�߽���ָ����ƶ����� 
		while(left<right && A[right]>temp)	//��ָ��δ��������ָ�����temp
			right--;		//��ָ���Լ�
		A[left]=A[right];	//��A[right]��ֵ�����շ���A[left]
		while(left<right && A[left]<=temp)	//��ָ��δ��������ָ��С�ڵ���temp
			left++;			//��ָ������
		A[right]=A[left];	//��A[left]���ÿշ��� 
	 } 
	 A[left]=temp;		//��ָ������ʱ��Ϊ���temp�Ŀշ���
	 return left;		//����temp��λ����Ϊtemp����ݹ�ı�Ҫ���� 
}
void randSelect(int A[],int left,int right,int K)
{
	if(left==right)	return ;	//�߽�
	int p=randPartition(A,left,right);	//ȷ�����ֺ����Ԫλ��
	int M=p-left+1;		//A[p]��A�еĵ�M�� 
	if(K==M)	return	;		//���ֺ�pǡ���ǵ�K��
	if(K<M)		//��K���������Ԫ���
		randSelect(A,left,p-1,K);	//����Ԫ����ҵ�K��
	else 		//��K���������Ԫ�Ҳ�
		randSelect(A,p+1,right,K-M);		//����Ԫ�Ҳ��ҵ�K-M��  
}
 
