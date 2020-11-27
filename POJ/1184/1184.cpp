#include<stdio.h>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 1000002
int vis[7][N];
int a0[10], b0[10], A, B;
struct node
{
    int k;///光标所在位置
    int num;
    int step;
};

void FenNum(int n, int a[])///把n的每位数字存到a数组中；
{
    int i=6;
    while(i)
    {
        a[i--]=n%10;
        n/=10;
    }
}

node Op(int a[], int op, node p)
{
    if(op==0)
        swap(a[p.k], a[1]);
    if(op==1)
        swap(a[p.k], a[6]);
    if(op==2 && a[p.k]!=9)
        a[p.k]++;
    if(op==3 && a[p.k]!=0)
        a[p.k]--;
    if(op==4 && p.k!=1)
        p.k--;
    if(op==5 && p.k!=6)
        p.k++;
    p.num=0;
    for(int i=1; i<=6; i++)
        p.num = p.num*10+a[i];
    return p;
}
int bfs(int num)
{
    node p;
    queue<node>Q;
    p.k=1;
    p.num = num;
    p.step = 0;
    Q.push(p);
    memset(vis, 0, sizeof(vis));
    vis[p.k][p.num] = 1;
    while(Q.size())
    {
        p=Q.front();
        Q.pop();
        if(p.num==B)
            return p.step;

        for(int i=0; i<6; i++)
        {
            FenNum(p.num, a0);
            if((i==4||i==5) && p.k<=5 && p.k>=2 &&  a0[p.k]!=b0[p.k])
                continue;
            node pn = Op(a0, i, p);
            if(vis[pn.k][pn.num]==0)
            {
                pn.step=p.step+1;
                Q.push(pn);
                vis[pn.k][pn.num] = 1;
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d", &A, &B);
    FenNum(B, b0);
    int ans = bfs(A);
    printf("%d\n", ans);
}
