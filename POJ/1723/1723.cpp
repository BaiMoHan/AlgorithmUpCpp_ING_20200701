#include <cstdio>
#include <algorithm>
#include <math.h>
#define SIZE 10004 //数组最大长度
int x[SIZE];
int y[SIZE];
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }
    sort(y+1, y + n+1); //对y排序
    sort(x+1, x + n+1);
    for (int i = 1; i <= n; i++)
    {
        x[i] = x[i] - i; //同时对x数组进行初始化
    }
    int mid;
    if(n%2)
        mid=n/2;
    else
    {
        mid=n/2+1;
    }
    

    int ans = 0;
    sort(x+1, x + n+1);
    for (int i = 1; i <=n; i++)
    {
        ans += abs(x[i] - x[mid]) + abs(y[i] - y[mid]);
    }
    printf("%d\n", ans);
    return 0;
}
