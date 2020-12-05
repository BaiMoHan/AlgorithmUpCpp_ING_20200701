#include<stdio.h>
#define OJ 98
#define N 1001
int main(){
	#ifndef OJ
	freopen("201412-1.txt","r",stdin);
	#endif 
	int a[N]={0};
	int n;
	scanf("%d",&n);
	int b;
	for(int i=0;i<n;i++){
		scanf("%d",&b);
		a[b]++;
		printf("%d",a[b]);
		if(i+1!=n)
			printf(" ");
	} 
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
