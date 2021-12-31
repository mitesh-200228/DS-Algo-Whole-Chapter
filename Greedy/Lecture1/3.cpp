// https://www.codechef.com/problems/RAMDEV

#include <unordered_set>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <queue>
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

// best for finding power of a^b in O(logn)
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
    ll l, b;
    cin >> l >> b;
    ll n;
    cin >> n;
    ll sum = 0;

    while (n--)
    {
        ll L, B;
        cin >> L >> B;

        ll x = (L / l) * (B / b);
        ll y = (L / b) * (B / l);
        sum += max(x, y);
    }
    cout<<sum<<endl;
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