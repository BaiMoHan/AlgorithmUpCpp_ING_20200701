#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 10004

int n;
int x[maxn], y[maxn];

int main()
{
	//freopen("t.txt", "r", stdin);
	scanf("%d", &n);
	for (int i =0; i < n; i++)
		scanf("%d%d", &x[i], &y[i]);
	sort(y, y + n);
	sort(x, x + n);
	for (int i =0; i < n; i++)
		x[i] -= i;
	sort(x, x + n);
	int a = (n +1) /2-1;
	int ans =0;
	for (int i =0; i < n; i++)
		ans += abs(y[a] - y[i]) + abs(x[a] - x[i]);
	printf("%d\n", ans);
	return 0;
}
