//��APPAPT�а����˶��ٸ�PAT����
#include<cstdio>
#include<cstring>
const int MAXN=10010; //�ַ�������󳤶�
const int MOD=100000007;	//Ϊ�����ܽ��̫�������ģ
char str[MAXN];		//�����ַ�������
int leftNumP[MAXN]={0};	//��ʼ����ĸA�����P��ĸ�ĸ���������� 
int main()
{
	scanf("%s",str);	//�����ַ���
	int len=strlen(str);//����ַ����ĳ���
	int i;		//����ѭ������
	for(i=0;i<len;i++)	//����leftNumP����,�����ַ����P��ĸ�ĸ���
	{
		if(str[i]=='P')	//��ǰ�ַ�ΪP
			leftNumP[i]=leftNumP[i-1]+1;//��ǰһλ�Ļ���������1
		else		//��ǰ�ַ�����P
			leftNumP[i]=leftNumP[i-1];	//P�ĸ�����ǰһλ����ͬ 
	 } 
	 int ans=0,rightNumT=0;	//��PAT����,�ַ��ұ�T�ĸ��� 
	for(i=len-1;i>=0;i--)	//��ĩβ��ǰ��ͳ��T�ĸ���,�����ַ�A 
	{
		if(str[i]=='T')	//��ǰ�ַ�ΪT
			rightNumT++;//��ǰT���ַ�����
		else if(str[i]=='A')//��ǰ�ַ�ΪA
			ans+=(leftNumP[i]*rightNumT)%MOD;	//�ۼӸ��� 
	}
	printf("����Ϊ%d",ans);	//������
	return 0; 
}







