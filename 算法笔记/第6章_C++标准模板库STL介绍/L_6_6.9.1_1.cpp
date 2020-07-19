//algorithm头文件下的常用函数
//max(),minx(),abs()
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int x=1,y=-2;
	printf("%d %d\n",max(x,y),min(x,y));
	printf("%d %d\n",abs(x),abs(y));
	return 0;
 } 
