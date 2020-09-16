#include<stdio.h>
#define M 1001
int main(){
	int n;
	scanf("%d",&n);
	int a[M]={0};
	for(int i=1;i<n;i++){
		scanf("%d",&a[i]);
	}
	long max=n;
	long temp=0;
	for(int i=1;i<n;i++){
		if(a[i]==1)
			continue;
		for(int j=i;a[i]<=a[j]&&j<=n;j++){
			temp+=a[i];
		}
		for(int j=i;a[i]<=a[j]&&j>=1;j--){
			temp+=a[i];
		}
		temp-=a[i];
		if(temp>max){
			max=temp;
		}
		temp=0;
	}
	printf("%d",max);
	return 0;
}
