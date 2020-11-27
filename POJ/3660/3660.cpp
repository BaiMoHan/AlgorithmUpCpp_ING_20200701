#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn = 110;
int a[maxn][maxn];
int n,m;
void Floyd()
{
    for(int k=1; k<=n; ++k)
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
}
int main()
{
    cin>> n >> m;
    mem(a,0);
    for(int i=0; i<m; ++i)
    {
        int u, v;
        cin>> u >> v;
        a[u][v] = 1;

    }
    Floyd();
    int res = 0;
    for(int i=1; i<=n; ++i)
    {
        int ans = 0;
        for(int j=1; j<=n; ++j)
        {
            if(a[i][j] || a[j][i])
                ans++;
        }
        if(ans == n-1)
            res++;
    }
    cout<< res <<endl;
    return 0;
}
