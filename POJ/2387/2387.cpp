#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn=1e3+5;
const int inf=0x3f3f3f3f;
int m,n,cnt,head[maxn],dis[maxn],vis[maxn];
typedef pair<int,int> PII;
priority_queue<PII,vector<PII>,greater<PII> > pq;

struct node{
    int v,w,nex;
}edge[maxn<<2];

void adde(int u,int v,int w){
    edge[++cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].nex=head[u];
    head[u]=cnt;
}

void dijkstra(){
    pq.push(make_pair(0,n));
    for(int i=1;i<=n;++i)
        dis[i]=inf;
    dis[n]=0;
    int num=0;
    while(!pq.empty()&&num<=n){
        int d=pq.top().first,u=pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        ++num;
        for(int i=head[u];i;i=edge[i].nex){
            int v=edge[i].v,w=edge[i].w;
            if(!vis[v]&&dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push(make_pair(dis[v],v));
            }
        }
    }
}

int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adde(u,v,w);
        adde(v,u,w);
    }
    dijkstra();
    printf("%d\n",dis[1]);
    return 0;
}
