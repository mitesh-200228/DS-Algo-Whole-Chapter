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
    std::vector<ll> v(n + 1);
    for (ll i = 0; i < n + 1; i++)
    {
        cin >> v[i];
    }
    bool allodd = false;
    bool twoodd = false;
    bool twoeven = false;
    bool alleven = false;
    if ((v[1] - v[0]) == 3)
    {
        alleven = true;
    }
    else if ((v[1] - v[0]) == 1)
    {
        twoodd = true;
    }
    else if ((v[1] - v[0]) == -1)
    {
        twoeven = true;
    }
    else if ((v[1] - v[0]) == -3)
    {
        allodd = true;
    }
    if (allodd || twoodd)
    {
        for (ll i = 1; i <= v[0]; i += 2)
        {
            for (ll j = i; j <= v[0]; j += 2)
            {
                if (((v[0] - i - j) + i + j == v[0]) && (v[0]-i-j)>=0 && (v[0]-i-j)<=n && i<=n && j<=n)
                {
                    if ((v[1] == ((1 ^ i) + (1 ^ j) + (1 ^ (v[0] - i - j)))))
                    {
                        if ((v[2] == ((2 ^ i) + (2 ^ j) + (2 ^ (v[0] - i - j)))))
                        {
                            cout << i << " " << j << " " << v[0] - i - j << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    else if (twoeven || alleven)
    {
        for (ll i = 0; i <= v[0]; i += 2)
        {
            for (ll j = i; j <= v[0]; j += 2)
            {
                if (((v[0] - i - j) + i + j == v[0])  && (v[0]-i-j)>=0 && (v[0]-i-j)<=n && i<=n && j<=n)
                {
                    if ((v[1] == (1 ^ i) + (1 ^ j) + (1 ^ (v[0] - i - j))))
                    {
                        if ((v[2] == (2 ^ i) + (2 ^ j) + (2 ^ (v[0] - i - j))))
                        {
                            cout << i << " " << j << " " << v[0] - i - j << endl;
                            return;
                        }
                    }
                }
            }
        }
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