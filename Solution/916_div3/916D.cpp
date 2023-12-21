//
// Created by Dikkoo on 2023/12/20.
//

#include <iostream>
#include <algorithm>

using namespace std;

// 测试样例个数
int t;
// 寒假天数 n
int n;
// 每天滑雪的人数为a，每天看电影的人数为b，每天玩桌游的人数为c
const int MAX = 1e5 + 10;
struct participant {
    int num, index;
} a[MAX], b[MAX], c[MAX];

// 比较参与人数
bool cmp(participant x, participant y) {
    return x.num > y.num;
}

int main() {

    // 输入测试样例个数
    cin >> t;

    // 处理每个测试样例
    while (t--) {

        // 输入寒假天数
        cin >> n;

        // 输入每天滑雪的人数
        for (int i = 1; i <= n; i++) {
            cin >> a[i].num;
            a[i].index = i;
        }
        // 输入每天看电影的人数
        for (int i = 1; i <= n; i++) {
            cin >> b[i].num;
            b[i].index = i;
        }
        // 输入每天玩桌游的人数
        for (int i = 1; i <= n; i++) {
            cin >> c[i].num;
            c[i].index = i;
        }

        // res为最终结果
        int res = 0;
        // 按照参与人数从大到小排序
        sort(a + 1, a + n + 1, cmp);
        sort(b + 1, b + n + 1, cmp);
        sort(c + 1, c + n + 1, cmp);
        // 循环判断每种活动的最大参与日是否一样，只有9种情况
        for(int i = 1; i <= 3; i++)
            for(int j = 1; j <= 3; j++)
                for(int k = 1; k <= 3; k++)
                    if(a[i].index != b[j].index && b[j].index != c[k].index && a[i].index != c[k].index)
                        res = max(res, a[i].num + b[j].num + c[k].num);

        // 输出结果
        cout << res << endl;
    }

    return 0;
}