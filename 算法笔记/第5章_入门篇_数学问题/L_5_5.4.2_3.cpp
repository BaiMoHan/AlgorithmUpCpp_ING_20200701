//����ɸ��
const int maxn=101;	//��
int prime[maxn],pnum=0;
bool p[maxn]={0};
void FindPrime(){
	for(int i=2;i<maxn;i++){//��2��ʼ,maxn-1����������д��i<=maxn
		if(p[i]==false){	//���i������
			prime[pnum++]=i;
			for(int j=i+i;i<maxn;j+=i){
				p[j]=true;//ɸȥ����i�ı��� 
			} 
		} 
	}
} 
