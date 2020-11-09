#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100000+5];
int n;
int temp;
bool check(int x)
{
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
       int t=upper_bound(a,a+n,a[i]+x)-a;//比a[i]+x小的元素的个数
       cnt+=(t-i-1);//排除a[i]之前的那些元素,共有i+1;
    }
    if(cnt>=temp) return true;  
        else return false;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
         for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
         sort(a,a+n);
         int m=n*(n-1)/2;
         temp=(m+1)/2;
         int l=0,r=a[n-1]-a[0];
         int ans;
         while(l<=r)//二分搜索
         {
             int mid=(l+r)>>1;
             if(check(mid))
              ans=mid,r=mid-1;
             else l=mid+1;
         }
         printf("%d\n",ans);
    }
    return 0;
}