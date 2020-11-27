//其实多组数据还是写的更模块化一点更好 
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

#define go(i,a,b) for(int i=a;i<=b;++i)
#define com(i,a,b) for(int i=a;i>=b;--i)
#define mem(a,b) memset(a,b,sizeof(a))

const int inf=0x3f3f3f3f,N=26;
const char A[]={'N','S','W','E'},a[]={'n','s','w','e'};
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

int n,m,T=0;
char s[N][N];
bool v[N][N][4];
string tmp;
struct node{
    int x,y,px,py;
    string ans;
};

bool pd(int x,int y){ return x>0&&x<=n&&y>0&&y<=m&&s[x][y]!='#'; }

bool bfs2(node p1,node p2){
    tmp="";
    node st;
    st.x=p1.px,st.y=p1.py;//起点 
    st.ans="";//记录移动方式 
    queue<node>q;
    q.push(st);
    bool vis[N][N];
    mem(vis,0);
    while(!q.empty()){
        node now=q.front(),nxt;
        q.pop();
        if(now.x==p1.x&&now.y==p1.y){
            tmp=now.ans;
            return 1;
        }
        go(i,0,3){
            nxt=now;
            nxt.x+=dx[i],nxt.y+=dy[i];
            int x=nxt.x,y=nxt.y;
            if(!pd(x,y)) continue;
            if(nxt.x==p2.x&&nxt.y==p2.y) continue;//不能经过箱子
            if(vis[x][y]) continue;
            vis[x][y]=1;
            nxt.ans=now.ans+a[i];
            q.push(nxt);
        }
    }
    return 0;
}

string bfs1(){
    node st=(node){-1,-1,-1,-1,""};
    for(int i=1;i<=n&&(st.x==-1||st.px==-1);++i)
        for(int j=1;j<=m&&(st.x==-1||st.px==-1);++j)
            if(s[i][j]=='B'){
                st.x=i,st.y=j;s[i][j]='.';
            }
            else if(s[i][j]=='S'){
                st.px=i,st.py=j;s[i][j]='.';
            }
    queue<node>q;
    q.push(st);
    mem(v,0);
    string ans="Impossible.";
    int cntans=inf,cnt=inf;
    while(!q.empty()){
        node pre,now=q.front(),nxt;
        q.pop();
        if(s[now.x][now.y]=='T'){
            int cntnow=0,l=now.ans.length();
            for(int i=0;i<l;++i){
                if(now.ans[i]>='A'&&now.ans[i]<='Z') ++cntnow;
            }
            if(cntnow<cntans||(cntnow==cntans)&&l<cnt){
                ans=now.ans;
                cntans=cntnow;cnt=l;
            }
            continue;
        }
        go(i,0,3){
            nxt=now;
            nxt.x+=dx[i],nxt.y+=dy[i];
            int x=nxt.x,y=nxt.y;
            if(!pd(x,y)) continue;
            pre=now;
            switch(i){
                case 0:pre.x=now.x+1;break;
                case 1:pre.x=now.x-1;break;
                case 2:pre.y=now.y+1;break;
                case 3:pre.y=now.y-1;break;
            }
            if(!bfs2(pre,now)) continue;
            if(v[x][y][i]) continue;
            v[x][y][i]=1;
            nxt.ans=now.ans+tmp;//当然是先动人再动箱子啦! 
            nxt.ans+=A[i];//按说这里人也是要动的，但此时题目不要求输出人的移动方向 
            nxt.px=now.x;
            nxt.py=now.y;
            q.push(nxt);
        }
    }
    return ans;
}

void work(){
    ++T;
    go(i,1,n) scanf("%s",s[i]+1);
    printf("Maze #%d\n",T);
    cout<<bfs1()<<endl<<endl;
}

int main(){
    //freopen("input.txt","r",stdin);
    while(cin>>n>>m&&n&&m) work();
    return 0;
}

