//分数f1和f2的加法,数学公式展开即可,最后结果化简 
 Fraction add(Fraction f1,Fraction f2){
 	Fraction result;
 	result.up=f1.up*f2.down +f1.down *f2.up ;//分数和的分子
	result.down =f1.down *f2.down ;//分数和的分母
	return reduction(result); 
 } 
