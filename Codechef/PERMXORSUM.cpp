#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        long long ans = 0;
        for (int i = 0; i < 30; i++)
        {
            int cnt = 0;
            if (n >= (1 << i))
            {
                cnt += max(0, n % (1 << (i + 1)) + 1 - (1 << i));
                cnt += n >> (i + 1) << i;
            }
            if (cnt * 2 <= n)
            {
                cnt = cnt * 2;
            }
            else
            {
                cnt = (n - cnt) * 2;
            }
            ans += (long long)cnt << i;
        }
        cout << ans << '\n';
    }
    return 0;
}