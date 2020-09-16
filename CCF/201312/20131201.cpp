#include<stdio.h>
#define M 10001
int a[M];
int main(){
	int n;
	scanf("%d",&n);
	int k;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		a[k]++;
	}
	int max=0;
	for(int i=1;i<M;i++){
		if(a[max]<a[i]){
			max=i;
		}
	}
	printf("%d",max);
	return 0;
}
