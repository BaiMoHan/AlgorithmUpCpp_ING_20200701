//���ݷ���n�ʺ�����,��n�лʺ����ڵ�����д��һ�����͹���һ��������
#include<stdio.h>
#include<math.h>
const int maxn=11;
bool flag;//���ݹ����еı�� 
int n,P[maxn],hashTable[maxn]={false},count;
//P������У�hashTable����������Ƿ��Ѿ��Ź�,count�����ʺ�ķŷ����� 
void generateP(int index);
int main()
{
	scanf("%d",&n);//����ʺ�ĸ���
	generateP(1);//��1��ʼ����������
	return 0; 
 } 
 void generateP(int index)
 {
 	if(index==n+1)//�ܵ��������˵�����Ƿ���Ҫ���
	 {
	 	count++;//�ڷŸ�������
		for(int i=1;i<=n;i++)//��ӡ�ڷŷ�ʽ 
			printf("%d",P[i]);
		printf("\n���ǵ�%d�ְڷŷ�ʽ\n",count);
		return ;
	  } 
	//�����д�1-n��˳��ö�٣��м�ע����ƻʺ��ж�����
	for(int x=1;x<=n;x++)//���ǵ�index�еĻʺ���ڵ�x���Ƿ���� 
	{
		if(hashTable[x]==false)
		{
		//˵����x�л�û�лʺ�
			flag=true;//˵������Ҫ��һ���ʺ� 
		//���濼�Ǵ��еĻʺ�������ͻ�ģ�������ǰ���1~x-1�еĻʺ�
			for(int pre=1;pre<index;pre++)//����֮ǰ�Ļʺ�
			{
		//��index�еĻʺ���к�Ϊx����pre�лʺ���к�ΪP[pre]
				if(abs(index-pre)==abs(x-P[pre]))//�ж��Ƿ����ʺ��ڶԽ�����
				{
					flag=false;//˵������x������
					break;//����ѭ�� 
				 } 
		 	} 
			 if(flag)//flagΪ�棬��˵�����԰�index�еĻʺ����x�д�
			 {
		 		P[index]=x;//�ѵ�index�еĻʺ���ڵ�x��
				hashTable[x]=true;//��x�в����ٷ��ûʺ�
				generateP(index+1);//�ݹ鴦���index+1�еĻʺ�Ӧ�÷��õ��к�
				hashTable[x]=false;//ÿһ�εݹ����֮����븴ԭ��ǣ��ſ��Կ�ʼ��һ�γ��� 
		  	}
		}
	 } 
 }
 
 
 
 
 
 
 
 
 
