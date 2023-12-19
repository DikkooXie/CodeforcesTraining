//
// Created by 10956 on 2023/12/19.
//
#include <iostream>

using namespace std;

// 测试样例个数
int t;
// 给定数位之和 s
int s;

int main() {

    // 输入测试样例个数
    cin >> t;

    // 依次处理每个测试样例
    for(int i = 0; i < t; i++) {
        // 定义结果字符串
        string result;

        // 输入数位之和
        cin >> s;

        // 如果数位之和小于10，直接输出数位之和
        if(s < 10) {
            cout << s << endl;
            continue;
        }

        // 如果数位之和大于等于10，从9开始遍历，直到把数位之和加满
        for(int j = 9; j > 0; j--) {

            // 如果数位之和大于等于当前数位，将当前数位加入结果中，并将数位之和减去当前数位
            if(s >= j) {
                // 将数字拼接到结果字符串中
                result += (char)(j + '0');
                // 将数位之和减去当前数位
                s -= j;
            }
        }

        // 从后往前输出字符串
        for(int j = result.length() - 1; j >= 0; j--) {
            cout << result[j];
        }
        cout << endl;
    }

    return 0;
}