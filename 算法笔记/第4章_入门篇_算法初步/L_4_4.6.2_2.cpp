//�鲢����ķǵݹ�ʵ��
void mergesort(int a[])
{
	//stepΪ����Ԫ�ظ�����step/2Ϊ������Ԫ�ظ�����ע��Ⱥſ��Բ�ȡ
	int step,i,mid;	//stepΪ������iΪ��������midΪÿ����е� 
	for(step=2;step/2<=n;step*=2)
	{
		//ÿstep��Ԫ��һ�飬����ǰstep/2�ͺ�step/2��Ԫ�ؽ��кϲ�
		for(i=1;i<=n;i+=step)	//��ÿһ�� 
		{
			mid=i+step/2-1;		//������Ԫ�ظ���Ϊstep/2
			if(mid+1<=n)	//���������Ԫ����ϲ�
			//������Ϊ[i,mid],������Ϊ[mid+1,min(i+step-1,n)]
				merge(a,i,mid,mid+1,min(i+step-1,n)); 
		}
	 } 
}
