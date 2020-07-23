//sort()处理结构体
#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int x,y;
}s[10];
bool cmp(node a,node b){ 
	return a.x>b.x;//按照结构体内x的值从大到小排序 
} 
int main(){
	s[0].x=1;
	s[0].y=22;
	s[1].x=-5;
	s[1].y=66;
	s[2].x=0;	
	s[2].y=100;
	for(int i=0;i<3;i++)
		printf("s[%d]:x=%d,y=%d\n",i,s[i].x,s[i].y);
	printf("\n");
	sort(s,s+3,cmp);
	for(int i=0;i<3;i++)
		printf("s[%d]:x=%d,y=%d\n",i,s[i].x,s[i].y);
	printf("\n");
	return 0;
} 
