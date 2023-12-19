//
// Created by Dikkoo on 2023/12/19.
//

#include <iostream>

using namespace std;

// 测试样例个数
int t;
// 给定序列的长度 n（最大值MAX）, 给定序列数组 a
const int MAX = 2e5 + 10;
int n, a[MAX];

int main() {
    // 输入测试样例个数
    cin >> t;

    // 依次处理每个测试样例
    for(int i = 0; i < t; i++) {
        // exist[i]表示数字i是否在给定序列中出现过
        int exist[MAX] = {0};

        // 输入给定序列的长度
        cin >> n;

        // 输入给定序列
        for(int j = 0; j < n; j++) {
            cin >> a[j];
        }

        // 从后往前遍历，如果这个数字存在过，输出结果（第几个有重复就删到哪里）并退出循环，否则将这个数字标记为存在
        for(int j = n - 1; j >= 0; j--) {

            // 如果这个数字存在过，输出结果并退出循环
            if(exist[a[j]] == 1) {
                // 输出结果
                cout << j + 1 << endl;
                break;
            }

            // 如果j为0，说明没有重复数字，输出0
            if(j == 0)
                cout << 0 << endl;

            // 将这个数字标记为存在
            exist[a[j]] = 1;
        }
    }

    return 0;
}
