//
// Created by Dikkoo on 2023/12/19.
//

#include <iostream>
#include <algorithm>

using namespace std;

// 测试样例个数 t
int t;
// 闹铃个数 n， 睡觉的时间 H:M
int n, H, M;
// 闹铃的时间 h:m（1 < n <= 100)
int h, m;
// 时间戳（00:00为0，之后每过一分钟加1）
int time[100+10];


// 时间均不含前导零

int main() {
    // 输入测试样例个数
    cin >> t;

    // 依次处理每个测试样例
    for(int i = 0; i < t; i++) {
        // 输入数据
        cin >> n >> H >> M;
        // 将睡觉时间的时间戳存储在time[0]中
        time[0] = H * 60 + M;

        // 输入闹钟时间并同时将闹铃时间转化为时间戳
        for(int j = 1; j <= n; j++) {
            cin >> h >> m;
            time[j] = h * 60 + m;
        }

        // 将闹钟时间排序
        sort(time + 1, time + n + 1);

        // 将time[n+1]初始化为最大值
        time[n+1] = 24 * 60;

        // 从后往前遍历，计算每个闹钟时间与睡觉时间的差值，并将最小差值存储在time[n+1]中
        for(int j = n; j > 0; j--) {
            time[j] = time[j] - time[0];
            if(time[j] < 0) {
                time[j] += 24 * 60;
            }
            if(time[j] < time[n+1]) {
                time[n+1] = time[j];
            }
        }

        // 输出睡眠的小时和分钟
        cout << time[n+1] / 60 << " " << time[n+1] % 60 << endl;
    }

    return 0;
}