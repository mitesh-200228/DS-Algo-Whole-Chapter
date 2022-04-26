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

ll finds(vector<ll> v, ll x)
{
    ll n = v.size();
    ll k = -1;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            k = i;
        }
    }
    return k;
}

void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    vector<ll> v(n);
    ll mn = INT_MAX;
    ll mx = INT_MIN;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mn = min(mn, v[i]);
        mx = max(mx, v[i]);
    }
    vector<ll> dummy = v;
    sort(dummy.begin(), dummy.end());
    ll str = 0;
    if (k + 1 >= n)
    {
        cout << mx << endl;
        return;
    }
    while (k > 0)
    {
        ll itr = finds(v, dummy[str]);
        if (itr != -1)
        {
            ll dst = itr;
            if (dst != 0 && dst != n - 1)
            {
                v[dst] = max(v[dst - 1], v[dst + 1]);
            }
            else if (dst == 0)
            {
                v[dst] = v[dst + 1];
            }
            else
            {
                v[dst] = v[dst - 1];
            }
        }
        str++;
        k--;
    }
    ll mn1 = INT_MAX;
    for (ll i = 0; i < n; i++)
    {
        mn1 = min(mn1, v[i]);
    }
    cout << mn1;
    cout << endl;
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