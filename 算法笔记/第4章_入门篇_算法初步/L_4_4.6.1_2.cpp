//�ϲ�����������
int merge(int a[],int b[],int c[],int n,int m) 
{
	//��a[n]��b[m]��������ϲ���c[]��
	while(i<n&j<m)
	{
		//ÿ�ν���С�����ϲ���c�� 
		if(a[i]<b[j])
			c[index++]=a[i];
		else
			c[index++]=b[j];
	 } 
	 //������һ������������Ԫ�������ʣ�µ���һ������ֱ�Ӻϲ� 
	 while(i<n)
	 	c[index++]=a[i++];
	 while(j<n)
	 	c[index++]=b[j++]; 
}
