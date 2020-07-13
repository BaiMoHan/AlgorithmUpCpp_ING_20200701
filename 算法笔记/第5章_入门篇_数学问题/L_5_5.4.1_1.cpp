bool isPrime(int n){
	if(n<1)
		return false;
	//需要用到math.h头文件 
	int sqr=(int)sqr(1.0*n);//根号n
	for(int i=2;i<=sqr;i++){
		if(n%i==0)//不能写成!n%i,应该是!(n%i) 
			return false;
	} 
	return ture;
} 
bool isPrime(int n){
	if(n<1)
		return false;
		//不需要开根号也能实现开根号 
	for(int i=2;i*i<=n;i++){
		if(!n%i)
			return false;
	} 
	return ture;
} 

