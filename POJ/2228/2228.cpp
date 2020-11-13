#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

const int N = 4000, INF = 0x3f3f3f3f;

int w[N];
int dp[2][N][2];//dp[i][]j[0~1]表示前i个小时中休息了j个小时，并且第i个小时为0 和 1 的状态，
//（0）：没有休息，（1）：休息
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;++i) 
		cin >> w[i];
    //在1处破环成链
    memset(dp, -0x3f, sizeof dp);
    dp[1][0][0] = 0;dp[1][1][1] = 0;
    for(int i = 2;i <= n;++i)
        for(int j = 0;j <= m;++j){
            dp[i%2][j][0] = max(dp[(i-1)%2][j][0], dp[(i-1)%2][j][1]);
            if(j)
                dp[i%2][j][1] = max(dp[(i-1)%2][j-1][0], dp[(i-1)%2][j-1][1] + w[i]);
        }

    int ans = max(dp[n%2][m][0], dp[n%2][m][1]);

    //补充剩下的情况,1处是环的情况
    memset(dp, -0x3f, sizeof dp);
    dp[1][1][1] = w[1];
    for(int i = 2;i <= n;++i)
        for(int j = 0;j <= m;++j){
            dp[i%2][j][0] = max(dp[(i-1)%2][j][0], dp[(i-1)%2][j][1]);
            if(j)
                dp[i%2][j][1] = max(dp[(i-1)%2][j-1][0], dp[(i-1)%2][j-1][1] + w[i]);
        }

    ans = max(ans, dp[n%2][m][1]);

    cout << ans << endl;
}


