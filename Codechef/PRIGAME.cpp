#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define ld long double
#define pll pair<ll, ll>
#define PB push_back
const int MOD = 1000000007; // 998244353
long long int inverse(long long int i)
{
    if (i == 1)
        return 1;
    return (MOD - ((MOD / i) * inverse(MOD % i)) % MOD + MOD) % MOD;
}
ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % MOD;
    ll temp = POW(a, b / 2);
    if (b % 2 == 0)
        return (temp * temp) % MOD;
    else
        return (((temp * temp) % MOD) * a) % MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll prime[1000001], pre[1000001];
    for (int i = 0; i < 1000001; i++)
    {
        prime[i] = 1;
    }
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = 2 * i; j <= 1000000; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    pre[0] = 0;
    pre[1] = 0;
    for (int i = 2; i <= 1000000; i++)
    {
        pre[i] = pre[i - 1] + prime[i];
    }
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (pre[x] < y + 1)
            cout << "Chef";
        else
            cout << "Divyam";
        cout << "\n";
    }
}