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
    ll m;
    cin >> m;
    std::vector<std::vector<ll>> v(n, std::vector<ll>(m, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    ll row_start = 0;
    ll col_start = 0;
    ll row_end = n-1;
    ll col_end = m-1;
    while (row_start <= row_end && col_start <= col_end)
    {
        for (ll i = row_start; i <= col_end; i++)
        {
            cout << v[row_start][i] << " ";
        }
        row_start++;
        for (ll i = row_start; i <= row_end; i++)
        {
            cout << v[i][col_end] << " ";
        }
        col_end--;
        for (ll i = col_end; i >= col_start; i--)
        {
            cout << v[row_end][i] << " ";
        }
        row_end--;
        for (ll i = row_end; i >= row_start; i--)
        {
            cout << v[i][col_start] << " ";
        }
        col_start++;
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