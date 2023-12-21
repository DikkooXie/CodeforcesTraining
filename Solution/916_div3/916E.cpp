//
// Created by Dikkoo on 2023/12/20.
//

#include <iostream>
#include <algorithm>

using namespace std;

// 测试样例个数 t
int t;

// 弹珠颜色数量 n
int n;

// 每种颜色的弹珠数量集合，a为爱丽丝拥有的弹珠数量，b为鲍勃拥有的弹珠数量
const int MAX = 2e5 + 10;
long long a[MAX], b[MAX];

// 对于爱丽丝来说，每选择一种颜色的弹珠对得分的影响为： (a[i] - 1) - (- b[i]) = a[i] + b[i] - 1
// 对于鲍勃来说，每选择一种颜色的弹珠对得分的影响为： (-a[i]) - (b[i] - 1) = -（a[i] + b[i] - 1）

// 对于爱丽丝来说，想让得分最大化，则需要让 a[i] + b[i] - 1 最大化，即 a[i] + b[i] - 1 最大化
// 对于鲍勃来说，想让得分最小化，则需要让 -（a[i] + b[i] - 1） 最小化，即 a[i] + b[i] - 1 最大化
// 所以只需比较a[i] + b[i] - 1的大小就可得到二者的最优策略，即谁的a[i] + b[i]大谁就先选（常数项相同可忽略）。

// c为每种颜色的弹珠数量之和，num为弹珠数量之和，index为颜色编号
struct sum {
    long long num, index;
} c[MAX];

// 比较弹珠数量之和，将弹珠数量之和从大到小排序
bool cmp (sum x, sum y) {
    return x.num > y.num;
}

int main() {

    // 输入测试样例个数
    cin >> t;

    // 依次处理每个测试样例
    while(t--) {
        // 输入弹珠颜色数量
        cin >> n;

        // 输入每种颜色的弹珠数量
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            c[i].num = a[i] + b[i];
            c[i].index = i;
        }

        sort(c + 1, c + n + 1, cmp);

        // scoreA为爱丽丝的得分，scoreB为鲍勃的得分
        long long scoreA = 0, scoreB = 0;

        // 爱丽丝（先手）和鲍勃（后手）轮流执行自己的最优操作，直到游戏结束（没有任何一种弹珠双方都有）
        for(int i = 1; i <= n; i ++) {
            if(i % 2 == 1) // 爱丽丝的回合
                scoreA += a[c[i].index] - 1;
            else // 鲍勃的回合
                scoreB += b[c[i].index] - 1;
        }

        // 输出结果
        cout << scoreA - scoreB << endl;
    }

    return 0;
}