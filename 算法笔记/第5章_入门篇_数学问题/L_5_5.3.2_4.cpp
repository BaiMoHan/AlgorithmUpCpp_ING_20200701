Fraction divide(Fraction f1,Fraction f2){
	//分数除法，数学展开最后化简
	Fraction result;
	result.up=f1.up *f2.down ;
	result.down =f1.down *f2.up ;
	return reduction(result);
	//注意除法遇到除以0按具体题目要求来 
}
