bool isPrime(int n){
	if(n<1)
		return false;
	//��Ҫ�õ�math.hͷ�ļ� 
	int sqr=(int)sqr(1.0*n);//����n
	for(int i=2;i<=sqr;i++){
		if(n%i==0)//����д��!n%i,Ӧ����!(n%i) 
			return false;
	} 
	return ture;
} 
bool isPrime(int n){
	if(n<1)
		return false;
		//����Ҫ������Ҳ��ʵ�ֿ����� 
	for(int i=2;i*i<=n;i++){
		if(!n%i)
			return false;
	} 
	return ture;
} 

