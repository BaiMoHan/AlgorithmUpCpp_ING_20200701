//素数筛法
const int maxn=101;	//表长
int prime[maxn],pnum=0;
bool p[maxn]={0};
void FindPrime(){
	for(int i=2;i<maxn;i++){//从2开始,maxn-1结束，不能写成i<=maxn
		if(p[i]==false){	//如果i是素数
			prime[pnum++]=i;
			for(int j=i+i;i<maxn;j+=i){
				p[j]=true;//筛去所有i的倍数 
			} 
		} 
	}
} 
