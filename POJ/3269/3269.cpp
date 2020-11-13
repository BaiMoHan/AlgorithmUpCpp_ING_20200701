#include<iostream>
#include<algorithm>
using namespace std;
 
#define size 10010       //2 <= N <= 10000
#define INF 0x3f3f3f3f
 
int x[size];
int y[size];
int original_x[size];
int original_y[size];
int minn,plan;  //��¼��Сֵ�ͷ�����
 
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		original_x[i] = x[i];
		original_y[i] = y[i];
	}
	sort(x, x + n);
	sort(y, y + n);
	if (n % 2 == 1) {  // ���n������
		int middle = n / 2;
		for (int i = 0; i < n; i++) {
			if (x[middle] == original_x[i] && y[middle] == original_y[i]) {  //���Ϊ�����ķ�����
				minn = INF;
				for (int j = 0; j < 4; j++) { //ö���ĸ������ϵĵ�
					int temp_x = x[middle] + dx[j];
					int temp_y = y[middle] + dy[j];
					int temp_minn = 0;
					for (int k = 0; k < n; k++) {
						temp_minn += abs(temp_x - x[k]) + abs(temp_y - y[k]);
					}
					if (temp_minn < minn) {
						minn = temp_minn;
						plan = 1;
					}
					else if (temp_minn == minn)
						plan++;
				}
				break;
			}
			minn += abs(x[middle] - x[i]) + abs(y[middle] - y[i]);
			plan = 1;
		}
	}
	else {  //���n��ż��
		int middle1 = n / 2 - 1;
		int middle2 = n / 2;
		plan = (x[middle2] - x[middle1] + 1)*(y[middle2] - y[middle1] + 1);
		for (int i = 0; i < n; i++) {
			minn += abs(x[middle1] - x[i]) + abs(y[middle1] - y[i]);      //���ѡһ�������ڵĵ㶼�У���Ϊ����������ڵ���Сֵ��ͬ
			if (original_x[i] <= x[middle2] && original_x[i] >= x[middle1] && original_y[i] <= y[middle2] && original_y[i] >= y[middle1])
				plan--;
		}
	}
	cout << minn << " " << plan << endl;
	return 0;
}