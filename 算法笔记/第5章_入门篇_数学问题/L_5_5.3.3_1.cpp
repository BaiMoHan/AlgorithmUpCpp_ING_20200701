void showResult(Fraction r){	//������� 
	r=reduction(r);	//�Ȼ���
	if(r.down==1)	//��ĸΪ1��������
		printf("%lld",r.up);
	else if(abs(r.up )>r.down ){	//�ٷ������ɴ�����
		printf("%d %d/%d",r.up/r.down ,abs(r.up)%r.down ,r.down );
		 
	}
	else	//�����
		printf("%d/%d",r.up ,r.down ); 
} 
