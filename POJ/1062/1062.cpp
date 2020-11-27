#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 105, M = 1e4 + 5, INF = 0x3f3f3f3f;
struct E {
    int v, w, next;
} e[M];
int k, n, x, u, v, w, maxL = INF, len = 1, L[N], h[N], d[N];//L[i]代表i的等级
bool vis[N];
void add(int u, int v, int w) {
    e[len].v = v;
    e[len].w = w;
    e[len].next = h[u];
    h[u] = len++;
}
void spfa(int l, int r) {
    memset(d, 0x3f, sizeof(d));
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int j = h[u]; j; j = e[j].next) {
            int v = e[j].v;
            int w = e[j].w + d[u];
            if (l <= L[v] && L[v] <= r && d[v] > w) {
                d[v] = w;
                if (!vis[v]) vis[v] = true, q.push(v);
            }
        }
    } 
}
int main() {
    scanf("%d%d", &k, &n);
    for (int u = 1; u <= n; u++) {
        scanf("%d%d%d", &w, &L[u], &x);
        maxL = max(maxL, L[u]);
        add(0, u, w);//0号点花费w的价值就可以买
        while (x--) {
            scanf("%d%d", &v, &w);
            add(v, u, w); //v-->u 有了v花费w就可以买u 
        } 
    }
    //枚举下等级范围 求出最小的ans
    int ans = INF;
    for (int i = L[1] - k; i <= L[1]; i++) { //等级范围 肯定是要包含1点的 不然你连1都无法购买 
        //可以和[i, i + k]区间的人交易
        spfa(i, i + k);
        ans = min(d[1], ans); 
    } 
    printf("%d", ans);
    return 0;
} 

