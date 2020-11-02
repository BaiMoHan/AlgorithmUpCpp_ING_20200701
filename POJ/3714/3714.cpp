#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long LL;

const LL INF=1000000000000;
const int N=100010;

struct Node{
	LL x,y;
	int flag;	//0为站台,1为士兵
	Node(LL x = 0, LL y = 0, int flag = 0) :x(x), y(y), flag(flag) {}
	//sort函数的cmp比较对<进行重载
	const bool operator < (const Node A) const{
		return x==A.x?y<A.y:x<A.x;
	} 
}no[2*N];

int n;

double dis(int a,int b){
	    return sqrt((double)((no[a].x - no[b].x)*(no[a].x - no[b].x) + (no[a].y - no[b].y)*(no[a].y - no[b].y)));
}


double solve(int l,int r){
	if(l==r)
		return INF;
	int mid=(r+l)>>1;//取中点二分
	double a=solve(1,mid);
	double b=solve(mid+1,r);
	double d=min(a,b);
	//找中间的部分,在[x-d,x+d]之间的带状区域考虑 
	for(int i=mid;i>=l;--i){
		//筛选出[x-d,x]之间的点 
		if(no[mid].x-no[i].x>d)
			break;
		//进一步筛选[x,x+d]之间的点 
		for(int j=mid+1;j<=r;++j){
			//两点横坐标<d，否则跳出循环 
			if(no[j].x-no[i].x>d)
				break;
			
			//算出两点间的距离 
            double tmp = dis(i, j);
            if (no[i].flag != no[j].flag&&tmp < d)d = tmp;
		}
	} 
	return d;
}


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lld %lld",&no[i].x,&no[i].y);
			no[i].flag=1;
		}
		
		for(int i=0;i<n;i++){
			scanf("%lld %lld",&no[i+n].x,&no[i+n].y);
			no[i+n].flag=2;
		}
		
		sort(no,no+2*n);
		double ans=solve(0,2*n-1);
		printf("%.3lf\n",ans);
	}
	return 0;
}
