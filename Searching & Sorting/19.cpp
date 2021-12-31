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

int find(std::vector<ll> &v, ll x)
{
    for (ll i = 0; i < v.size(); i++)
    {
        if (v[i] == x)
        {
            return i + 1;
        }
    }
    return -1;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll ans1 = 0;
        ll ans2 = 0;
        ll x;
        cin >> x;
        ll z = find(v, x);
        // cout<<z<<"---";
        if (z == -1)
        {
            if (x > v[n - 1])
            {
                z = n;
                ans1 += z;
                for (ll i = 0; i < z; i++)
                {
                    ans2 += v[i];
                }
                cout << ans1 << " " << ans2 << endl;
            }
            else
            {
                cout << "0 0" << endl;
            }
        }
        else
        {
            // z = n;
            ans1 += z;
            for (ll i = 0; i < z; i++)
            {
                ans2 += v[i];
            }
            cout << ans1 << " " << ans2 << endl;
        }

        // cout<<ans1<<endl;
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