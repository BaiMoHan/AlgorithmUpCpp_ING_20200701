//循环出四个方面的最长序列然后len[i][j]=max(len[上],下,左,右)+1;
#define OJ 0

#include <cstdio>
#define N 101
using namespace std;
int map[N][N],len[N][N];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int r,c;
int dp(int i,int j){
    if(len[i][j]!=0)
		return len[i][j];
    int maxx=0,s;
    for(int t=0;t<4;t++){
          int temx=i+dir[t][0],temy=j+dir[t][1];
          if(temx>=0&&temx<r&&temy>=0&&temy<c&&map[temx][temy]<map[i][j]){
              s=dp(temx,temy);
              if(s>maxx)
			  	maxx=s;
          }
           
      }
    len[i][j]=maxx+1;
    return maxx+1;
}
 
int main(){
    #ifndef OJ
    freopen("1088.txt","r",stdin);
    #endif
		scanf("%d %d",&r,&c);
        int mx=-1;
        for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
			   scanf("%d",&map[i][j]);
		   }
		}
        for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
			   len[i][j]=dp(i,j);
			   if(len[i][j]>mx){
			      mx=len[i][j]; 
			   }
		   }         
        }
		printf("%d\n",mx);

    #ifndef  OJ
    fclose(stdin);
    #endif
    
	    return 0;
}
