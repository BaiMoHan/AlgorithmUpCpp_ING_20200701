#include<stdio.h>
#define N 1001
int main(){
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
	return 0;
}
