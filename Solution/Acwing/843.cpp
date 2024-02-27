#include <iostream>

int row_pos[10], n;
bool col[10], p[40], q[40];

void print_result()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            if(row_pos[i] == j) {
                std::cout << "Q";
            }
            else
                std::cout << ".";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return;
}

void dfs(int i)
{
    if(i == n) {
        print_result();
        return;
    }
    for(int j = 0; j < n; j++){
        if(col[j] || p[i + j] || q[i - j + 9])
            continue;
        else
            row_pos[i] = j;
        col[j] = p[i + j] = q[i - j + 9] = true;
        dfs(i+1);
        col[j] = p[i + j] = q[i - j + 9] = false;
    }
}

int main()
{
    std::cin >> n;
    dfs(0);
    return 0;
}