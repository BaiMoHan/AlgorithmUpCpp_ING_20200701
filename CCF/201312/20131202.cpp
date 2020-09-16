#include<stdio.h>
int main(){
	char a[15];
	scanf("%s",a);
	char c=a[12];
	int k[15];
	for(int i=0;i<12;i++)
		k[i]=a[i]-'0';
	long  n=(long)((k[0]*1+k[2]*2+k[3]*3+k[4]*4+k[6]*5+k[7]*6+k[8]*7+k[9]*8+k[10]*9)%11);
	if(n==10){
		if(a[12]=='X'){
			printf("Right");
			return 0;
		}
		else{
			a[12]='\0';
			printf("%s",a);
			printf("X");
			return 0;
		}
	}
	if(a[12]-'0'==n){
		printf("Right");
		return 0;
	}
	a[12]='\0';
	printf("%s",a);
	printf("%d",n);
	return 0;
}
