//�������е�һ�����ڵ���x���������ֲ���
int lower_bound(int a[],int left,int right,int n)
{
	//�������½�Ϊ����ұ����䣬����ĳ�ֵΪ0-n������n
	int mid;	//midΪleft��right���е�
	while(left<right)//ע��˴��޵��ںţ�left==right��Ϊ�ҵ���λ�� 
	{
		mid=left+(right-left)/2;//�����Ա�̣�ȡ�е�
		if(a[mid]>=x)		//�м�������ڵ������ 
		{		 
			right=mid;		//��������[left,mid]����,ע���ʱ����Ҫmid-1 
		} 
		else 
		{
			left=mid+1;		//������˵�����Ϊmid+1 
		 } 
	 } 
	 return left;			//left==right��Ϊ�г�����λ�� 
 } 
