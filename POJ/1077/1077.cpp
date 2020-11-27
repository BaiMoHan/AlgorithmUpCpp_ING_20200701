#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<algorithm>
#define R register int
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1},end=54480996;
const int py[]={0,1,2,0,1,2,0,1},px[]={0,0,0,1,1,1,2,2};
const char op[4]={'u','r','d','l'};
using namespace std;
inline int g() {
    R ret=0; register char ch; while(!isdigit(ch=getchar()));
    do ret=ret*10+(ch^48); while(isdigit(ch=getchar())); return ret;
}
struct node{ int sta,g,h; node() {}
    node(int ss,int gg,int hh) {sta=ss,g=gg,h=hh;}
    bool operator <(const node& y) const {return g+h>y.g+y.h;}
}; int a[3][3];
map<int,int> d,pre,dir;
priority_queue<node> q;
inline bool ckpos(int x,int y) {return x<0||x>2||y<0||y>2;}
inline int calc(int p[3][3]) { R ret=0;
    for(R i=0;i<3;++i) for(R j=0;j<3;++j) ret=ret*9+p[i][j]; return ret;
}
inline pair<int,int> recalc(int vl,int p[3][3]) { R x,y;
    for(R i=2;i>=0;--i) for(R j=2;j>=0;--j) {
        p[i][j]=vl%9,vl/=9; if(p[i][j]==0) x=i,y=j;
    } return make_pair(x,y);
}
inline int h(int p[3][3]) { R ret=0;
    for(R i=0;i<3;++i) for(R j=0;j<3;++j) {
        if(p[i][j]==0) continue;
        ret+=abs(i-px[p[i][j]-1])+abs(j-py[p[i][j]-1]);
    } return ret;
}
inline int Astar() {
    d.clear(),pre.clear(),dir.clear();
    while(q.size()) q.pop(); R st=calc(a); d[st]=0;
    q.push(node(st,0,h(a)));
    while(q.size()) {
        node u=q.top(); R crt=q.top().sta; q.pop();
        if(crt==end) return u.g;
        R a[3][3]; register pair<int,int> blk=recalc(crt,a); R x=blk.first,y=blk.second;
        for(R i=0;i<4;++i) { R xx=x+dx[i],yy=y+dy[i];
            if(ckpos(xx,yy)) continue; swap(a[x][y],a[xx][yy]);
            R nxt=calc(a); if(d.find(nxt)==d.end()||d[nxt]>d[crt]+1) 
                d[nxt]=d[crt]+1,pre[nxt]=crt,dir[nxt]=i,q.push(node(nxt,d[nxt],h(a)));//此处存了nxt的上一个状态和如何操作
            swap(a[xx][yy],a[x][y]);
        }
    } return -1;
}
inline void print(int s) {
    if(pre.find(s)==pre.end()) return;
    print(pre[s]); putchar(op[dir[s]]);
}
signed main() {
    for(R i=0;i<3;++i) for(R j=0;j<3;++j) { register char ch;
        while(!isdigit(ch=getchar())&&ch!='x');
        if(ch=='x') a[i][j]=0;
        else a[i][j]=ch^48;
    } R ans=Astar(); if(ans==-1) printf("unsolvable"),putchar('\n'); else print(end);
}
