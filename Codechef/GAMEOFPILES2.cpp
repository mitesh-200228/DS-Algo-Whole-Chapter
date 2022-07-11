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
    vector<ll> v(n);
    ll a = 0, b = 0, c = 0, d = 0, e = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 1)
        {
            c++;
        }
        else
        {
            if (v[i] == 2)
            {
                b++;
            }
            d += v[i];
            e++;
            if (v[i] % 2)
            {
                a++;
            }
        }
    }
    if (c == 1)
    {
        if (!(a % 2))
        {
            cout << "CHEF" << endl;
            return;
        }
        if (b == 0)
        {
            cout << "CHEFINA" << endl;
            return;
        }
        d -= 2;
        e--;
        if ((d - e) % 2)
        {
            cout << "CHEFINA" << endl;
            return;
        }
        else
        {
            cout << "CHEF" << endl;
            return;
        }
    }
    else if (c > 1)
    {
        if ((d - e) % 2)
        {
            cout << "CHEF" << endl;
            return;
        }
        else
        {
            cout << "CHEFINA" << endl;
            return;
        }
    }
    if (a % 2)
    {
        cout << "CHEF" << endl;
        return;
    }
    else
    {
        cout << "CHEFINA" << endl;
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