#include<stdio.h>
#define PI 3.1415926
int main(){
	float f1,f2;
	int n;
	scanf("%d",&n);
	int count;
	float area=0,num;
	int i=1;
	while(i<=n){
		scanf("%f",&f1);
		scanf("%f",&f2);
		area=0;
		count=0;
		num=0;
		area+=f1*f1;

		area+=f2*f2;
		area*=PI;
		area/=2;
		do{
			count++;
			num+=50;
		}while(area>num);
		printf("Property %d: This property will begin eroding in year %d.\n",i,count);
		i++;
	}
	printf("END OF OUTPUT.");
} 
