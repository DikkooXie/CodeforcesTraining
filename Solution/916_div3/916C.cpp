//
// Created by Dikkoo on 2023/12/20.
//

#include <iostream>

using namespace std;

// 测试样例个数
int t;

// 任务数量 n ， 可以完成的最大任务量 k
int n, k;

// 每个任务第一次得解的经验值集合 a, 后续得解的经验值集合 b
const int MAX = 2e5 + 10;
int a[MAX], b[MAX];

// a 的前缀和数组 sum_a
// b 到当前元素的最大值数组 max_b（max_b[i] 表示 b[0] 到 b[i] 的最大值）
int sum_a[MAX], max_b[MAX];

int main() {

    // 输入测试样例个数
    cin >> t;

    // 处理每个测试样例
    while (t--) {

        // 输入任务数量、最大可完成任务量
        cin >> n >> k;

        // 输入每个任务第一次得解的经验值
        for (int i = 1; i <= n; ++i) {

            cin >> a[i];
            // 输入同时计算前缀和
            sum_a[i] = sum_a[i - 1] + a[i];
        }

        // 输入每个任务后续得解的经验值
        for (int i = 1; i <= n; ++i) {

            cin >> b[i];
            // 输入同时计算到当前元素的最大值
            max_b[i] = max(max_b[i - 1], b[i]);
        }

        // 计算可获得的最大经验值
        int exp = 0;
        // 遍历每个任务，i的含义为当前已完成到第 i 个任务，第 1 到第 i 个任务再次完成只能获得后续得解的经验值
        for (int i = 1; i <= n; ++i) {

            // 计算完成到第 i 个任务后，剩余可完成任务量
            int remain = k - i;

            // 如果剩余可完成任务量小于 0 ，则退出循环
            if (remain < 0) break;

            // 计算完成当前任务后，可获得的最大经验值
            // 最大经验值 = 第 1 到第 i 个任务第一次得解的经验值之和 + 第 1 到第 i 个任务后续得解的经验值的最大值 * 剩余可完成任务量
            int cur_exp = sum_a[i] + max_b[i] * remain;
            // 更新最大经验值
            exp = max(exp, cur_exp);
        }

        // 输出最大经验值
        cout << exp << endl;
    }

    return 0;
}
