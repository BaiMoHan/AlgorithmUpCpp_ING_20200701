const int maxn=101;//素数表长
int prime[maxn],pNum=0; //prime数组存放所有的素数，pNum为素数的个数
bool p[maxn]={0};//p[i]===true表示i是素数
void Find_Prime(){
	for(int i=1;i<maxn;i++){	//注意不能写成i<=maxn
		 if(isPrime(i)==true){
		 	prime[pNum++]=i;//把素数i装入素数表
			p[i]=true; 
		 } 
	}
} 
