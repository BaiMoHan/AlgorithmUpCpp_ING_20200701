//��������
#include<cstdio>
#include<cmath>
struct Fraction{
	int up,down;
}; 
Fraction reduction(Fraction result){
	if(result.down<0){	//��ĸΪ��������Ӻͷ�ĸ������෴��
		result.up=-result.up;
		result.down=-result.down; 
	}
	if(result.up==0){	//����Ϊ0,��ĸΪ1 
		result.down=1;
	}else{	//������Ϊ0��Լ�� 
		int d=gcd(abs(result.up),abs(result.down));//�����Լ����ע�������ֵ
		result.up/=d;
		result.down/=d; 
	}
	return result;
}
