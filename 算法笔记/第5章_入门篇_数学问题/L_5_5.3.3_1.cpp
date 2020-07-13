void showResult(Fraction r){	//输出分数 
	r=reduction(r);	//先化简
	if(r.down==1)	//分母为1，即整数
		printf("%lld",r.up);
	else if(abs(r.up )>r.down ){	//假分数化成带分数
		printf("%d %d/%d",r.up/r.down ,abs(r.up)%r.down ,r.down );
		 
	}
	else	//真分数
		printf("%d/%d",r.up ,r.down ); 
} 
