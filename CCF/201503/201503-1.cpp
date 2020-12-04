#include<stdio.h>
#define OJ 98 
int map1[1000][1000]={0};
int map2[1000][1000]={0};
int main(){
	#ifndef OJ
	freopen("201503-1.txt","r",stdin);
	#endif 
	int n,m;
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&map1[i][j]);
			
	for(int i=0;i<n;i++)
		for(int j=m-1;j>=0;j--){
			map2[m-1-j][i]=map1[i][j];
		}
		
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			printf("%d ",map2[i][j]);
		if(i+1!=m)
			printf("\n");
	}

//	for(int j=m-1;j>=0;j--){
//		for(int i=0;i<n;i++)
//			printf("%d ",map1[i][j]);
//		printf("\n");
//	}s
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
} 
