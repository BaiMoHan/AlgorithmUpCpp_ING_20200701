#include <iostream>
#include<string.h> 
using namespace std;

int m;        //������
int n;        //������
int f[25];    //������ʼ����
int d[25];    //��ÿ5���Ӽ�����Ŀ
int left_fish[25];    //ʣ�µ���
int t[24];    //ÿ������֮���·������
int plan[25];    //ÿ��������ͣ��ʱ��
int temp[25];	//�洢�м�̰����̽���Եķ��� 
int max_cnt;    //�������
int cnt;


//���м䷽�����Ƶ�plan�� 
inline void update() {
    for (int i = 0; i < n; ++i) 
		plan[i] = temp[i];
}

void process() {
    memset(plan, 0, sizeof(plan));
    //��ʼ��������� 
    max_cnt = -1;
    int flag = true;
    //��ʼ��·��������ʱ�� 
    int time_on_the_road = 0;
    //��ʼ������ʣ��ʱ�� 
    int time_fishing = m;
    //ö�����г���Ϊ�յ�����
    for (int i = 0; i < n; ++i)
	{
        cnt = 0;
        memset(temp, 0, sizeof(temp));
        time_fishing = m - time_on_the_road;
        for (int k = 0; k < n; ++k) 
			left_fish[k] = f[k];

        //̰�Ĳ��� 
        while (true)
		 {
            if (time_fishing < 5) 
				break;    //ʱ�������
				
            int most = -1;//��ǰ���������� 
            int lake_id;//��ǰ���ǵĳ��� 
            
            //�ӵ�һ�����������һ������,�ҳ�·���������������� 
            for (int j = 0; j <= i; ++j) {
                if (left_fish[j] > most) {
                    most = left_fish[j];
                    lake_id = j;//��¼�ҵ���������ID 
                }
            }
            if (most == 0) {
                temp[0] += time_fishing / 5 * 5;
                break;    //û������
            }
            //������ͣ����ʱ����� 
            temp[lake_id] += 5;
            //���������������� 
            cnt += left_fish[lake_id];
            //��һ�ε��㣬������ʣ�¶����� 
            left_fish[lake_id] -= d[lake_id];
            if (left_fish[lake_id] < 0) 
				left_fish[lake_id] = 0;
            time_fishing -= 5;
        }
        if (cnt > max_cnt) {
            max_cnt = cnt;
            update();
        } else if (cnt == max_cnt) {
        	//����з�����ͬ�ģ�����������ѡ���׸���������ʱ����� 
            for (int i = 0; i < n; ++i) {
                if (temp[i] < plan[i]) 
					break;
                if (temp[i] > plan[i])    
					update();
            }
        }
        time_on_the_road += t[i];
        if (time_on_the_road > m) 
			break;    //�������ߵ��ó���
    }
    cout << plan[0];
    for (int i = 1; i < n; ++i) cout << ", " << plan[i];
    cout << endl << "Number of fish expected: " << max_cnt << endl << endl;
}

int main(void) {
    while (true) {
        cin >> n;//��ȡn������ 
        if (n == 0) break;
        cin >> m;	//��ȡ�ܹ�ʱ�� 
        m *= 60;    //Сʱת��Ϊ����
        
        //��ȡÿһ�������Ļ������� 
        for (int i = 0; i < n; ++i) 
			cin >> f[i];
			
		//��ȡÿһ��������ʱ����� 
        for (int i = 0; i < n; ++i) 
			cin >> d[i];
			
		//��ȡ�������·�̺�ʱ 
        for (int i = 0; i < n - 1; ++i) {
            cin >> t[i];
            t[i] *= 5;    //תΪ������
        }
        process();
    }
    return 0;
}
