//����f1��f2�ļӷ�,��ѧ��ʽչ������,��������� 
 Fraction add(Fraction f1,Fraction f2){
 	Fraction result;
 	result.up=f1.up*f2.down +f1.down *f2.up ;//�����͵ķ���
	result.down =f1.down *f2.down ;//�����͵ķ�ĸ
	return reduction(result); 
 } 
