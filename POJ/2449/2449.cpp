#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
inline const int read(){
    register int x=0,f=1;
    register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int N=1e3+10;
const int M=1e5+10;
const int inf=1e9;
struct asd{
    int v,w,next;
}e1[M],e2[M];
bool vis[N];
struct node{
    int id;///当前节点编号
    int f;//f表示经过当前节点的最短路
    int g;//g表示S->当前节点的最短路
    node(int id=0,int f=0,int g=0):id(id),f(f),g(g){}
    bool operator <(const node &a)const{
        if(f==a.f) return g>a.g;
        return f>a.f;
    }
};
int tot,n,m,K,head1[N],head2[N];
int dis[N];//dis[i]表示当前点i到终点T的最短路径 
void add(int x,int y,int z){
    ++tot;
    e1[tot].v=y;e1[tot].w=z;e1[tot].next=head1[x];head1[x]=tot;
    e2[tot].v=x;e2[tot].w=z;e2[tot].next=head2[y];head2[y]=tot;
}
void Spfa(int S){//更新每个点->n点的最短距离
    queue<int>q;
    for(int i=1;i<=n;i++) dis[i]=inf;
    dis[S]=0;
    vis[S]=1;
    q.push(S);
    while(!q.empty()){
        int x=q.front();q.pop();
        vis[x]=0;
        for(int i=head2[x];i;i=e2[i].next){
            int v=e2[i].v,w=e2[i].w;
            if(dis[v]>dis[x]+w){
                dis[v]=dis[x]+w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v); 
                }
            }
        }
    } 
}
void A_Star(int S,int T){
    if(S==T) K++;//坑 
    priority_queue<node>q;
    q.push(node(S,0,0));
    int cnt=0;
    while(!q.empty()){
        node h=q.top();q.pop();
        if(h.id==T){
            if(++cnt==K){
                printf("%d",h.f);//返回第k短路
                return ;
            }
        }
        for(int i=head1[h.id];i;i=e1[i].next){
            q.push(node(e1[i].v,h.g+e1[i].w+dis[e1[i].v],h.g+e1[i].w));//最短路更新k短路 
        }
    }
    puts("-1");
}
int main(){
    n=read();m=read();
    for(int i=1,x,y,z;i<=m;i++){
        x=read();y=read();z=read();
        add(x,y,z);
    }
    int S,T;
    S=read();T=read();K=read();
    Spfa(T);//预处理，反向遍历 
    A_Star(S,T);
    return 0;
}

