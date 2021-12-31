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
ll solve(ll n,std::vector<ll> &v,ll k,vector<ll> &dp)
{
    if (k < 0)
        return INT_MAX;
    if (k == 0)
        return 0;
    if (dp[k] != -1)
        return dp[k];
    ll currVal = INT_MAX;
    for (ll j = 0; j < v.size(); j++){
        if(k - v[j] <0) continue;
        currVal = min(currVal, solve(n,v,k-v[j],dp));
    }
    dp[k] = (currVal == INT_MAX) ? -1 : (1+currVal);
    return dp[k];
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
        ll n;
        cin >> n;
        ll k;
        cin >> k;
        std::vector<ll> v(n);
        std::vector<ll> dp(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cout << solve(n,v,k,dp);
    }
    return 0;
}