const int maxn=101;//������
int prime[maxn],pNum=0; //prime���������е�������pNumΪ�����ĸ���
bool p[maxn]={0};//p[i]===true��ʾi������
void Find_Prime(){
	for(int i=1;i<maxn;i++){	//ע�ⲻ��д��i<=maxn
		 if(isPrime(i)==true){
		 	prime[pNum++]=i;//������iװ��������
			p[i]=true; 
		 } 
	}
} 
