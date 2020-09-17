#include<stdio.h>\
#define M 11
struct Node{
	int x1,x2;
	int y1,y2;
	int num;
}note[11];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a,b;
	for(int i=1;i<n+1;i++){
		scanf("%d",&a);
		note[i].x1=a;
		scanf("%d",&a);
		note[i].y1=a;
		scanf("%d",&b);
		note[i].x2=b;
		scanf("%d",&b);
		note[i].y2=b;
		note[i].num=i;
	}
	struct Node temp;
	temp.num=0;
	temp.x1=0;
	temp.x2=0;
	temp.y1=0;
	temp.y2=0;
	int flag=0;
	for(int i=0;i<m;i++){
		flag=0;
		scanf("%d %d",&a,&b);
		for(int j=n;j>0;j--){
			if(note[j].x1<=a&&a<=note[j].x2&&note[j].y1<=b&&b<=note[j].y2){
				printf("%d",note[j].num);
				//½»»»
				temp=note[n];
				note[n]=note[j];
				note[j]=temp;

				flag=1;
				break;
			}	
		}
		if(flag==0)
			printf("IGNORED");
		if(i+1!=m)
			printf("\n");		
	}
	return 0;
}
