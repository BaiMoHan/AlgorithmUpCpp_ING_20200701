Fraction multi(Fraction f1,Fraction f2){
	//分数乘法，数学展开最后化简
	Fraction result;
	result.up =f1.up *f2.up ;
	result.down =f1.down *f2.down ;
	return reduction(result); 
}
