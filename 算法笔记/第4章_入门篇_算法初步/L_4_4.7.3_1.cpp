//���ѡ���㷨�����ڿ���˼��
//randPartition����Ϊ�����е����ѡ����Ԫ����������
//randSelect������a�з��ص�K��ĺ��� 
int randSelect(int a[],int left,int right,int K) 
{
	if(left==right)		return a[left];	//�߽�
	int p=randPartition(a,left,right);	//����һ�ο��Ż��ֲ�������Ԫ��λ��
	int M=p-left+1;		//��ʱa[p]Ϊ�����еĵ�M��
	if(K==M)		//Kǡ�õ���M,˵���ҵ���K�����
		return a[p];	//��ʱa[p]���ǵ�K�����
	else if(K<M)	//K��MС��˵����K�������a[p]�����
		return randSelect(a,left,p-1,K);	//��a[p]����ߵ������ѡ���㷨
	else		//K>M�����,˵����K�������a[p]���ұ�
		return randSelect(a,p+1,right,K-M);	//���Ҳ�Ѱ��K-M�����,���ʻ�������a�ĵ�K����� 
}
//�����㷨δ����K���Ϸ������ 

