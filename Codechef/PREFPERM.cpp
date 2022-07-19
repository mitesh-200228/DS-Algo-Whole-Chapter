#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod = 998244353;
ll pw(ll x, ll y)
{
    if (y == 0)
        return 1;
    if (y % 2)
        return x * pw(x, y - 1) % mod;
    ll res = pw(x, y / 2);
    return res * res % mod;
}
int a[200001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            a[i] = i;
        if (k == 1)
        {
            cout << n << ' ';
            for (int i = 1; i < n; i++)
                cout << i << ' ';
            cout << '\n';
        }
        else if (k % 2 == n % 2)
        {
            for (int i = 0; i < (n - k) / 2; i++)
            {
                swap(a[n - i * 2], a[n - i * 2 - 1]);
            }
            for (int i = 1; i <= n; i++)
                cout << a[i] << ' ';
            cout << '\n';
        }
        else
        {
            for (int i = 0; i <= (n - k) / 2; i++)
            {
                swap(a[i * 2 + 1], a[i * 2 + 2]);
            }
            for (int i = 1; i <= n; i++)
                cout << a[i] << ' ';
            cout << '\n';
        }
    }
}