//next_permutation()给出一个序列在全排列中的下一个序列
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[10]={1,2,3,4,5,6};
	//a[0]~a[2]之间的序列需要求解next_permutation
	do{
		printf("%d%d%d\n",a[0],a[1],a[2]);
	} while(next_permutation(a,a+6));//next_permutation在已经达到全排列的最后一个时会返回false 
	return 0;
 } 
