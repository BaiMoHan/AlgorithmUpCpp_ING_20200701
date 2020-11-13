#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string.h>
using namespace std;

typedef pair<double, double> PDD; //区间的结构
const int N = 1100;				  //小岛的最大个数
const double eps = 1e-6 /*算出来的坐标的精度*/, INF = 1e10;

int n, d;
PDD seg[N]; //点对区间数组

int main()
{
	int k = 1;
	while (true)
	{
		memset(seg, 0, sizeof(seg));
		cin >> n >> d;
		if (n == 0 || d == 0)
			break;
		//标记是否有可行解
		bool success = true;

		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			if (y > d)
			{
				//如果最短距离y都大于雷达范围就说明没有解
				success = false;
			}
			//算出区间的距离
			double len = sqrt(d * d - y * y);
			seg[i].first = x + len;
			seg[i].second = x - len;
		}

		if (!success)
		{
			printf("Case %d: -1\n", k);
			// break;
		}
		else
		{
			//首先按照区间右端点进行排序
			sort(seg, seg + n);
			int res = 0;
			double last = -INF;
			for (int i = 0; i < n; i++)
			{
				if (seg[i].second > last + eps)
				{
					res++;
					last = seg[i].first;
				}
			}
			printf("Case %d: %d\n", k, res);
		}
		k++;
	}
	return 0;
}
