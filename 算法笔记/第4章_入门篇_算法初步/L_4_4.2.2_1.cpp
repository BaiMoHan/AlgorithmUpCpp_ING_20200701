//����N���ַ�������ǡ����λ��д��ĸ��ɣ����ٸ���M����ѯ�ַ�����
//��ÿ����ѯ�ַ�����N���ַ����г��ֵĴ���
#include<stdio.h>
const int maxn=100;
char S[maxn][5],temp[5];
int hashTable[26*26*26+10];
int hashFunc(char S[],int len);//hash���������ַ���ת��Ϊ���� 
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);//n���ַ�����m����ѯ��
	for(int i=0;i<n;i++)//����n����
	{
		scanf("%s",S[i]);
		int id=hashFunc(S[i],3);//���ַ���ת��Ϊ����
		hashTable[id]++; //���ַ������ֵĴ���+1 
	 } 
	 for(int i=0;i<m;i++)
	 {
	 	scanf("%s",temp);//��ȡ��ѯ��
		int id=hashFunc(temp,3);//���ַ���tempת��Ϊ����
		printf("%d\n",hashTable[id]); 
	 }
 } 
 int hashFunc(char s[],int len)
 {
 	int id=0;
 	for(int i=0;i<len;i++)
 		id=id*26+(s[i]-'A');//��26����ת��Ϊʮ����
	return id; 
  } 
