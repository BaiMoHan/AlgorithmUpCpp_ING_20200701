#include<stdio.h>
int main()
{
	int count[10],book[10],total=0,sum,x,y,z,i;
	//count�ֱ����ڼ���ԲȦ���������book�����������1-9���Ѿ������
	for(count[1]=1;count[1]<=9;count[1]++)
	 	for(count[2]=1;count[2]<=9;count[3]++)
	 		for(count[3]=1;count[3]<=9;count[3]++)
	 			for(count[4]=1;count[4]<=9;count[4]++)
	 				for(count[5]=1;count[5]<=9;count[5]++)
	 					for(count[6]=1;count[6]<=9;count[6]++)
	 						for(count[7]=1;count[7]<=9;count[7]++)
	 							for(count[8]=1;count[8]<=9;count[8]++)
	 								for(count[9]=1;count[9]<=9;count[9]++)
	 								{
	 									for(i=1;i<=9;i++)//��ʼ���������
										 book[i]=0;
										for(i=1;i<=9;i++)
										 book[count[i]]=1;//����ȷ����Щ���ù�
										sum=0;
										//ͳ�Ƴ����˶��������� 
										for(i=1;i<=9;i++)
										  sum+=book[i];
										//�ж��Ƿ��������ʽ 
										x=count[1]*100+count[2]*10+count[3];
										y=count[4]*100+count[5]*10+count[6];
										z=count[7]*100+count[8]*10+count[9];
										printf("%d,%d,%d",x,y,z); 
										if(sum==9&&x+y==z)
										{
											total++;
											printf("%d+%d=%d\n",x,y,z);
										}
									 }
	printf("�ܹ���%d�ֺ������",total/2);
	return 0;
}

