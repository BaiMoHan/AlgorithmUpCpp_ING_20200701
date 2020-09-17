/*#include<stdio.h>
#include<algorithm>
#define N 1002
using namespace std;
int main(){
	int num[N]={0};
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
		
	sort(num,num+n);
	int count=0;
	for(int i=0;i<n;i++){
		if(num[i]+1==num[i+1])
		  count++;
	}
	printf("%d",count);
	return 0;
}*/


//Í°ÅÅÐòË¼ÏëÐ´·¨
#include<stdio.h>
#define N 10001
int main(){
	int num[N]={0};
	int n,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		num[k]=1;
	}
	int count=0;
	for(int i=0;i<N;i++){
		if(num[i]&&num[i+1])
			count++;
	}
	
	printf("%d",count);
	return 0;
} 




