Fraction minu(Fraction f1,Fraction f2){
	//����������ͬ����ѧչ����󻯼�
	Fraction result;
	result.up =f1.up *f2.down -f2.up *f1.down ;
	result.down =f1.down *f2.down ;
	return reduction(result); 
}
