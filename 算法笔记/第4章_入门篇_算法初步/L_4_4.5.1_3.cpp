//�ҵ����������е�һ������x������λ�ã����ֲ��ҷ�
int upper_bound(int a[],int left,int right,int x)
{
	int mid;		//ȡ�����е�
	while(left<right)	//��left==right��Ϊ����λ��
	{
		mid=left+(right-left)/2;	//ȡ�е㣬�����Ա��
		if(a[mid]>right)	//�ҵ�һ�����ڵģ���������ȴ˴�����Ҫ�ӵȺ� 
			right=mid;		//��������Ҫmid+1����Ϊ���ҵ�һ��
		else 
			left=mid+1;		//��[mid,right]�������� 
	 } 
	 return left;			//���ؼг�����λ�� 
 } 
