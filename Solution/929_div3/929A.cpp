#include <iostream>

using namespace std;

int t, n, a[60], ans;

int main()
{
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        ans = 0;
        cin >> n;

        for(int j = 0; j < n; j++)
        {
            cin >> a[j];
            if(a[j] < 0)
                ans -= a[j];
            else
                ans += a[j];
        }

        cout << ans << endl;
    }
}