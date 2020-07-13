int gcd(int a,int b){
	if(!b)
		return a;
	else
		return gcd(b,a%b);
		
	return !b?a:gcd(b.a%b);
}
