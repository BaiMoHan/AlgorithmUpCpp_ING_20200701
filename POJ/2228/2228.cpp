#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

const int N = 4000, INF = 0x3f3f3f3f;

int w[N];
int dp[2][N][2];//dp[i][]j[0~1]��ʾǰi��Сʱ����Ϣ��j��Сʱ�����ҵ�i��СʱΪ0 �� 1 ��״̬��
//��0����û����Ϣ����1������Ϣ
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;++i) 
		cin >> w[i];
    //��1���ƻ�����
    memset(dp, -0x3f, sizeof dp);
    dp[1][0][0] = 0;dp[1][1][1] = 0;
    for(int i = 2;i <= n;++i)
        for(int j = 0;j <= m;++j){
            dp[i%2][j][0] = max(dp[(i-1)%2][j][0], dp[(i-1)%2][j][1]);
            if(j)
                dp[i%2][j][1] = max(dp[(i-1)%2][j-1][0], dp[(i-1)%2][j-1][1] + w[i]);
        }

    int ans = max(dp[n%2][m][0], dp[n%2][m][1]);

    //����ʣ�µ����,1���ǻ������
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


