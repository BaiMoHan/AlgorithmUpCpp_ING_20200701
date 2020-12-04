#include<stdio.h>
#define OJ 98 
#define M 1001
int main(){
	#ifndef OJ
	freopen("201403-1.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	int a[M]={0};
	int b=0;
	for(int i=0;i<n;i++){
		scanf("%d",&b);
		if(b<0)
			b=-b;
		a[b]+=1;
	}
	int count=0;
	for(int i=0;i<M;i++){
		if(a[i]>=2)
			count++;
	}
	printf("%d",count);
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
} 
