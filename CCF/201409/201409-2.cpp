#include<stdio.h>
#define M 101
#define OJ 98
#define N 100
int main(){
	#ifndef OJ
	freopen("201409-2.txt","r",stdin);
	#endif 
	int n;
	scanf("%d",&n);
	int x1,y1,x2,y2;
	int map[M][N]={0};
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		for(int j=x1;j<x2;j++)
			for(int k=y1;k<y2;k++)
				map[j][k]=1;
	} 
	int count=0;
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			if(map[i][j])
				count++;
		
		
	printf("%d",count);
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0; 
}
