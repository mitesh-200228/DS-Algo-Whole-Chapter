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

void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    ll mx = INT_MIN;
    std::vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    ll mx2 = INT_MIN;
    if (k > 0)
    {
        for (ll i = 0; i < n; i++)
        {
            v[i] = mx - v[i];
            mx2 = max(mx2, v[i]);
        }
        k--;
    }

    if (k % 2 == 0)
    {
        for (ll i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    else
    {
        for (ll i = 0; i < n; i++)
        {
            v[i] = mx2 - v[i];
            cout << v[i] << " ";
        }
        cout << endl;
        return;
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