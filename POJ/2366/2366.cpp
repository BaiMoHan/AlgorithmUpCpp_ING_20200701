#include<stdio.h>
int search(int arr1[],int arr2[]);
int main(){
	int m,n;
	scanf("%d",&m);
	int arr1[m];
	for(int i=0;i<m;i++)
		scanf("%d",&arr1[i]);
	scanf("%d",&n);
	int arr2[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr2[i]);
	
	//two piont
	int i=m-1;
	int j=n-1;
	int result;
	while(i>0&&j>0){
		result=arr1[i]+arr2[j];
		if(result==10000){
			printf("YES");
			return 0;
		}else if(result>10000){
			i--;
		}else
			j--;
	}
	printf("NO");
	return 0; 	 
} 

