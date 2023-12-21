//
// Created by Dikkoo on 2023/12/20.
//

#include <iostream>

using namespace std;

// 测试样例个数
int t;
// 三位候选人的得票数 a, b, c
int a, b, c;

int main()
{

    // 输入测试样例个数
    cin >> t;

    // 依次处理每个测试样例
    while(t--) {

        // 输入三位候选人的得票数
        cin >> a >> b >> c;

        // 输出每位候选人超过其他两个候选人需要的票数
        cout << max(0, max(b, c) - a + 1) << " " << max(0, max(a, c) - b + 1) << " " << max(0, max(a, b) - c + 1) << endl;
    }

    return 0;
}