Fraction divide(Fraction f1,Fraction f2){
	//������������ѧչ����󻯼�
	Fraction result;
	result.up=f1.up *f2.down ;
	result.down =f1.down *f2.up ;
	return reduction(result);
	//ע�������������0��������ĿҪ���� 
}
