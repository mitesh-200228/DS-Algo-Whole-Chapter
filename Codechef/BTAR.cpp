#include <unordered_set>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <cmath>
#include <math.h>
#include <limits>
#define ll long long int
const ll N = 1e5 + 2, MOD = 1e9 + 7;
using namespace std;
int power(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2)
        {
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}
ll countSetBits(ll n)
{
    ll count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

ll gcd(ll a, string b)
{
    ll res = 0;
    for (int i = 0; i < b.length(); i++)
    {
        res = ((res * 10) + (b[i] - '0')) % a;
    }
    return __gcd(a, res);
}

void print(vector<ll> v, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}

void solve()
{
    ll n;
    cin >> n;
    int a[4] = {0, 0, 0, 0};
    ll x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        a[x % 4] += 1;
    }
    if ((a[1] + 2 * a[2] + 3 * a[3]) % 4 == 0)
    {
        int ans = min(a[3], a[1]);
        a[3] -= ans;
        a[1] -= ans;
        ans += a[2] / 2;
        a[2] %= 2;
        if (a[2])
        {
            ans += 2;
            a[2] = 0;
            if (a[3])
            {
                a[3] -= 2;
            }
            if (a[1])
            {
                a[1] -= 2;
            }
        }
        if (a[1])
        {
            ans += (a[1] / 4) * 3;
        }
        if (a[3])
        {
            ans += (a[3] / 4) * 3;
        }
        cout << ans << "\n";
    }
    else
    {
        cout << "-1\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}