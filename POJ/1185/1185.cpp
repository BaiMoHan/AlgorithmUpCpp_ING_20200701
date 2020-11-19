#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int dp[110][100][100], num[105], tem[105], top;
int mp[110];

//get函数用统计state=x的时候有多少个1
int get(int x)
{
    int ans = 0;
    while (x)
    {
        if (x & 1)
            ans++;
        x >>= 1;
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        int sum = 0;
        cin >> s;
        //读取数据的时候来转换为二进制位数的形式
        for (int j = 0; j < m; j++)
            if (s[j] == 'P')
                //如果第j列有一个P,说明能放置,那么对应该行的statex=x而言
                //x在二进制表示时第j位应该为1,二进制最右边的一位相当于是第m列
                sum += 1 << (m - j - 1); //构建地图，1是能放置，0是不能放

        //mp[i]记录的是第i行的地图状态,二进制位数表示
        mp[i] = sum;
    }

    //进行状态枚举,最大m个1实际上是1<<m-1
    for (int i = 0; i < (1 << m); i++)
    {
        //检测同行的炮兵是否摆放合法
        //如果两个炮台相邻,那么左移一位就可以让1的那位重合
        //如果两个炮台不相邻,但是在攻击范围内,那么左移两位可以让1的那位重合
        if (i & (i << 1) || i & (i << 2))
            continue; 
        //满足行状态的i记录到tmp数组中
        tem[top] = i;
        //同时获取该状态下摆放了多少个炮台
        num[top++] = get(i);
    }

// 每个状态可以影响到往下两层，所以要枚举当前行状态，
// 上一行状态以及上上行的状态，同样，记录的时候也要再加一维，
// dp[i][j][k]表示，放好前i行，第i行状态为j，第i-1行状态为k的时候，能放置的最大数量，
// 因为求的是最多的放置数量，也就需要求每个状态1的个数，
// 所以也需要预处理出每个状态对应的1的数量。
    for (int i = 0; i < top; i++) //因为枚举的时候要往上枚举两行，所以要处理出第一行的值，
    // 第一行不需要考虑与上面冲突
        if ((mp[1] | tem[i]) == mp[1])
        //对应地图的位放炮兵才合理
            dp[1][i][0] = num[i];


    //从第2行开始,第0行是0000000
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < top; j++)
        {
            //j表示第i行的状态
            if ((tem[j] | mp[i]) != mp[i])
                continue; //只能在地图上为1的地方放置
            //k表示第i-1行的状态
            for (int k = 0; k < top; k++)
            {
                if (tem[k] & tem[j])
                    continue; //与上一行冲突
                for (int r = 0; r < top; r++)
                {
                    //与上上行冲突或者前两行互相冲突
                    if (tem[r] & tem[j] || tem[k] & tem[r])
                        continue;                                             

                    //取max 
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][r] + num[j]); 
                }
            }
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < top; j++)
            for (int k = 0; k < top; k++)
                ans = max(ans, dp[i][j][k]); //注意要遍历所有状态，求出最大值
    cout << ans << endl;
    return 0;
}
