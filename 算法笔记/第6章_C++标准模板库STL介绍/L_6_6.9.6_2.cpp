//��sort()��double����������
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	double a[]={1.5,55.39,4589.0596,-3.55};
	for(int i=0;i<4;i++)
		printf("%f ",a[i]);
	printf("\n\n");
	sort(a,a+4);
	for(int i=0;i<4;i++)
		printf("%f ",a[i]);
	return 0;
 } 
