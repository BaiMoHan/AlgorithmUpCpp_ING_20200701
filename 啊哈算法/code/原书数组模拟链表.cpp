#include<stdio.h>
int main()
{
	int data[101],right[101];
	int i,n,t,len;
	//�����Ѿ��е���
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&data[i]);
	 } 
	 len=n;
	 //��ʼ������right
	 for(i=1;i<=n;i++)
	 {
	 	if(i!=n)
	 	{
	 		right[i]=i+1;
		 }
		 else
		 {
		 	right[i]=0;//���һλ��û����һλ 
		 }
	 }
	 //ֱ��������data��ĩβ��һ������
	 len++;
	 scanf("%d",&data[len]);
	 
	 //�������ͷ����ʼ����
	 t=1;
	 while(t!=0)
	 {
	 	if(data[right[t]]>data[len])
		 //�����ǰ�����һ������ֵ���ڴ������������嵽�м�
		 {
		 	right[len]=right[t];
		 	right[t]=len;
		 	break;//������ɣ�����ѭ�� 
		 } 
		 t=right[t];//ָ����һλ���൱�������p=p->next; 
	  } 
	  //�����������е���
	  t=1;
	  while(t!=0)
	  {
	  	printf("%d ",data[t]);
	  	t=right[t];
	   } 
	   return 0;
 } 
