#include <iostream>

using namespace std;

int ans = 0;
int ang[6][6] = {{},0, 1,0, 1, 0, 1};

void dfs(int i, int j, int k) // i为操作，(j,k)分别为结果的位置行列
{
    // 执行操作
    if(i == 1)
        ang[j][k] = ang[j-1][k] & ang[j-1][k+1];
    else if(i == 2)
        ang[j][k] = ang[j-1][k] | ang[j-1][k+1];
    else if(i == 3)
        ang[j][k] = ang[j-1][k] ^ ang[j-1][k+1];

    // 判断是否填完数字，判断结果是否正确
    if(j == 5 && k == 1)
    {
        if(ang[j][k] == 1)
            ans++;
        return;
    }

    // 判断三角形是否换行
    if(j+k == 6)
    {
        j++;
        k = 1;
    }
    else
        k++;

    // 三种操作遍历
    for(int r = 1; r <= 3; r++)
        dfs(r, j, k);
}

int main()
{
    // i为操作，(j,k)分别为结果的位置行列
    for(int i = 1; i <= 3; i++)
        dfs(i, 2, 1);
    cout << ans;
    return 0;
}