//�õݹ������ȫ��������
#include<cstdio>
const int maxn=11;//��Ϊ��0-9��ʮ���� 
int n,P[maxn],hashTable[maxn]={false};//PΪ��ǰ���У�hashTable��¼����x�Ƿ��Ѿ���P��
void generateP(int index);
int main()
{
	n=5;//���3��ȫ���� 
	generateP(1);//��1��ʼ��̽ 
	return 0;
}
void generateP(int index)
{
	if(index==n+1)//�ݹ�߽磬˵��1-nλ�Ѿ��ź�
	{
		//����Ѿ��źõ�����
		for(int i=1;i<=n;i++)
			printf("%d",P[i]);
		//��������������ӡһ���ո� 
		printf("\n"); 
		return ;//�ݹ���� 
	 } 
	 for(int x=1;x<=n;x++)//ö��1-n����ͼ��x����P[index]
	 {
	 	if(hashTable[x]==false)//˵��x����P�У���������
		 {
		 	P[index]=x;//��x���뵱ǰ����
			hashTable[x]=true;//���x�Ѿ���P��
			generateP(index+1);//������һ��λ������
			hashTable[x]=false;//�Ѿ�������P[index]�������⣬��ԭ״̬���ſɽ�����һ�γ��� 
		  } 
	  } 
	 
 } 
