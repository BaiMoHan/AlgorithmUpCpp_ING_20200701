#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-15
#define MAXN  50005
#define INF 1000000007
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
#define mem(a) memset(a,0,sizeof(a))

struct EDGE//使用邻接表存边
{
    int v;
    int w;
    int next;
}edge[3*MAXN];
int head[MAXN], d[MAXN], vis[MAXN],N, n, Max,Min;

void AddEdge(int u,int v,int w)//添加新边
{
    edge[N].v = v;
    edge[N].w = w;
    edge[N].next = head[u];
    head[u] = N++;
}

void SPFA()//此题数据较大，用Bellman-ford恐怕过不了
{
    for(int i=Min;i<=Max;i++) d[i] = -INF;
    d[Min] = 0;
    queue<int>q;
    q.push(Min);
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        vis[x] = 0;
        for(int e=head[x];e != -1;e=edge[e].next)if(d[edge[e].v] < d[x] + edge[e].w)
        {
            d[edge[e].v] = d[x] +edge[e].w;
            if(!vis[edge[e].v])
            {
                q.push(edge[e].v);
                vis[edge[e].v] = 1;
            }
        }
    }//由于题目说一定有解，我就略去了判断是否存在负权回路
}

int main()
{
    while(~scanf("%d", &n))
    {
        int u,v,w; N = 0;
        memset(head,-1,sizeof(head));
        mem(vis);  mem(edge);
        Min = INF;  Max = -INF;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d", &u,&v,&w);//题目条件的边
            AddEdge(u,v+1,w);
            Min = MIN(Min, u);//在这里记录最小值和最大值，所求的就是以Min为源点
            Max = MAX(Max, v+1);//以Max为终点的最短路
        }
        for(int i = Min;i < Max; i++)//添加新边
        {
            AddEdge(i,i+1,0);
            AddEdge(i+1,i,-1);
        }
        SPFA();
        printf("%d\n", d[Max]);
    }
    return 0;
}
