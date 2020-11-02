#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int MAXN=250;
struct po{
	int a[10000];
}s[MAXN+5];
int tot=1;
void init(){
	s[0].a[0]=1;
	s[1].a[0]=1;
	for(int i=2;i<=MAXN;i++){
	    int c=0,temp;
		for(int j=0;j<tot;j++){
		    temp=s[i-1].a[j]+2*s[i-2].a[j]+c;
		    s[i].a[j]=temp%100000;
		    c=temp/100000;
		}
		if(c>0){
			s[i].a[tot++]=c;
		}	
	}
	return;
}
int main(){
	init();
	int n;
	while(~scanf("%d",&n)){
		int i; 
		for(i=tot-1;s[n].a[i]==0;i--);
		printf("%d",s[n].a[i]);
		for(int j=i-1;j>=0;j--){
			printf("%05d",s[n].a[j]);
		}
		printf("\n");
	}
	return 0;
} 
