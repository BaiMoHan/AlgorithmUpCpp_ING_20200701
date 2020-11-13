#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string.h>
using namespace std;

typedef pair<double, double> PDD; //����Ľṹ
const int N = 1100;				  //С����������
const double eps = 1e-6 /*�����������ľ���*/, INF = 1e10;

int n, d;
PDD seg[N]; //�����������

int main()
{
	int k = 1;
	while (true)
	{
		memset(seg, 0, sizeof(seg));
		cin >> n >> d;
		if (n == 0 || d == 0)
			break;
		//����Ƿ��п��н�
		bool success = true;

		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			if (y > d)
			{
				//�����̾���y�������״ﷶΧ��˵��û�н�
				success = false;
			}
			//�������ľ���
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
			//���Ȱ��������Ҷ˵��������
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
