#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ll long long int

using namespace std;
const int maxn = 1e6 + 10, maxm = 1e6 + 10, mod = 1e9 + 7;
ll dp[maxn];
ll add(ll a, ll b)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}
ll mul(ll a, ll b)
{
    a *= b;
    if (a >= mod)
        a %= mod;
    return a;
}
ll rpe(ll a, ll b)
{
    ll ans = 1;
    while (b != 0)
    {
        if (b & 1)
            ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}
int main()
{
    dp[0] = 1;
    for (int i = 1; i < maxn; i++)
        dp[i] = dp[i - 1] * 2 % mod;
    int t;
    cin >> t;
    int n, m;
    while (t--)
    {
        cin >> n >> m;
        cout << rpe((dp[n] + mod - 1) % mod, m) << endl;
    }
}