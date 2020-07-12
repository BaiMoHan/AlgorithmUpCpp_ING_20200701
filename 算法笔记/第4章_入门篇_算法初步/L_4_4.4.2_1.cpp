//贪心区间的问题
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=110;
struct Inteval{
	int x;
	int y;
}inteval[maxn];
bool cmp(struct Inteval a,struct Inteval b)
{
	//先按照左端点从大到小排序
	if(a.x!=b.x)
		return a.x>b.x;
	//再按照右端点从小到大排序，为了腾出更多的空间 
	else
		return a.y<b.y; 
		 
 } 
 int main()
 {
 	int n,i,count=1,lastx;
 	while(scanf("%d",&n),n!=0)//针对多组输入样例 
 	{
 		//读入区间信息
		 for(i=0;i<n;i++)
		 	scanf("%d %d",&inteval[i].x,&inteval[i].y);
		//将区间进行排序
		sort(inteval,inteval+n,cmp);
		lastx=inteval[0].x;//初始化取第一个区间的左端点
		for(i=1;i<n;i++)
		{
			if(inteval[i].y<=lastx)//如果该区间的右断点比上一个区间的左端点海啸
			{
				//则此两区间无交集
				lastx=inteval[i].x;
				count++; 
			 } 
		 } 
		 printf("能最多构成%d个两两没有交集的区间\n",count);
	 }
	 return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
