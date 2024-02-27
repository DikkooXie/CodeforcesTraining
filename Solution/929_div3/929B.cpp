#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 10;
int t, n, ans;
int a[MAX];

int main()
{
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        ans = 0;
        int num[4] = {0};
        cin >> n;

        for(int j = 0; j < n; j++)
        {
            cin >> a[j];
            num[a[j] % 3]++;
            ans += a[j] % 3;
        }

        int result = 0;
        ans = ans % 3;

        while(ans)
        {
            if(num[ans]){
                result++;
                break;
            }
            else {
                result ++;
                ans++;
                ans = ans % 3;
                if(num[2])
                    num[0]++;
                if(num[0])
                    num[1]++;
                if(num[1])
                    num[2]++;
            }
        }

        cout << result << endl;
    }
}