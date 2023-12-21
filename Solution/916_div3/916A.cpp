//
// Created by Dikkoo on 2023/12/20.
//

#include <iostream>

using namespace std;

// 测试样例个数
int t;
// 给定序列的长度以及竞赛时间（分钟） n
int n;
// 问题类型（A-Z）
char problem;

int main()
{

    // 输入测试样例个数
    cin >> t;

    // 依次处理每个测试样例
    while(t--) {

        // 解题数量 sum
        int sum = 0;
        // 标记问题A-Z的思考时间（分钟）
        int solved[26] = {0};

        cin >> n;

        for(int i = 1; i <= n; i++) {

            // 输入问题
            cin >> problem;

            // 该问题思考时间 +1
            solved[problem - 'A'] ++;

            // 如果该问题思考时间等于所需时间，说明该问题已经解决，解决数量+1
            if (solved[problem - 'A'] == problem - 'A' + 1)
                sum ++;
        }

        // 数据解题数量
        cout << sum << endl;
    }
}
