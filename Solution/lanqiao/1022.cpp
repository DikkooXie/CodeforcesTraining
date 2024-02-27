#include <iostream>

using namespace std;

int ans = 0;
bool box[5][5];

void dfs(int i, int u, int v)
{
    if(i == 16){
        ans++;
        return;
    }

    box[u][v] = true;

    if(u-1 >= 0 && !box[u-1][v])
        dfs(i+1, u-1, v);
    if(v-1 >= 0 && !box[u][v-1])
        dfs(i+1, u, v-1);
    if(v+1 < 4 && !box[u][v+1])
        dfs(i+1, u, v+1);
    if(u+1 < 4 && !box[u+1][v])
        dfs(i+1, u+1, v);

    box[u][v] = false;
}

int main()
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            dfs(1, i, j);
    cout << ans;
    return 0;
}