#include <iostream>
#include<string.h> 
using namespace std;

int m;        //分钟数
int n;        //池塘数
int f[25];    //池塘初始鱼数
int d[25];    //鱼每5分钟减少数目
int left_fish[25];    //剩下的鱼
int t[24];    //每两池塘之间的路径长度
int plan[25];    //每个池塘的停留时间
int temp[25];	//存储中间贪心试探策略的方案 
int max_cnt;    //最大期望
int cnt;


//将中间方案复制到plan中 
inline void update() {
    for (int i = 0; i < n; ++i) 
		plan[i] = temp[i];
}

void process() {
    memset(plan, 0, sizeof(plan));
    //初始化最大收益 
    max_cnt = -1;
    int flag = true;
    //初始化路径上消耗时间 
    int time_on_the_road = 0;
    //初始化钓鱼剩余时间 
    int time_fishing = m;
    //枚举所有池塘为终点的情况
    for (int i = 0; i < n; ++i)
	{
        cnt = 0;
        memset(temp, 0, sizeof(temp));
        time_fishing = m - time_on_the_road;
        for (int k = 0; k < n; ++k) 
			left_fish[k] = f[k];

        //贪心策略 
        while (true)
		 {
            if (time_fishing < 5) 
				break;    //时间耗完了
				
            int most = -1;//当前最大池塘收益 
            int lake_id;//当前考虑的池塘 
            
            //从第一个鱼塘到最后一个鱼塘,找出路径中最大收益的鱼塘 
            for (int j = 0; j <= i; ++j) {
                if (left_fish[j] > most) {
                    most = left_fish[j];
                    lake_id = j;//记录找到的鱼塘的ID 
                }
            }
            if (most == 0) {
                temp[0] += time_fishing / 5 * 5;
                break;    //没有鱼了
            }
            //该鱼塘停留的时间更新 
            temp[lake_id] += 5;
            //该鱼塘钓起来的鱼 
            cnt += left_fish[lake_id];
            //下一次钓鱼，该鱼塘剩下多少鱼 
            left_fish[lake_id] -= d[lake_id];
            if (left_fish[lake_id] < 0) 
				left_fish[lake_id] = 0;
            time_fishing -= 5;
        }
        if (cnt > max_cnt) {
            max_cnt = cnt;
            update();
        } else if (cnt == max_cnt) {
        	//如果有方案相同的，按照题意是选择首个池塘花费时间最长的 
            for (int i = 0; i < n; ++i) {
                if (temp[i] < plan[i]) 
					break;
                if (temp[i] > plan[i])    
					update();
            }
        }
        time_on_the_road += t[i];
        if (time_on_the_road > m) 
			break;    //不可能走到该池塘
    }
    cout << plan[0];
    for (int i = 1; i < n; ++i) cout << ", " << plan[i];
    cout << endl << "Number of fish expected: " << max_cnt << endl << endl;
}

int main(void) {
    while (true) {
        cin >> n;//读取n个池塘 
        if (n == 0) break;
        cin >> m;	//读取总共时长 
        m *= 60;    //小时转化为分钟
        
        //读取每一个池塘的基础收益 
        for (int i = 0; i < n; ++i) 
			cin >> f[i];
			
		//读取每一个池塘的时间减量 
        for (int i = 0; i < n; ++i) 
			cin >> d[i];
			
		//读取池塘间的路程耗时 
        for (int i = 0; i < n - 1; ++i) {
            cin >> t[i];
            t[i] *= 5;    //转为分钟数
        }
        process();
    }
    return 0;
}
