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
    string s;
    cin >> s;
    ll zero = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            zero++;
        }
    }
    ll operations = 0;
    vector<pair<ll, ll>> p;
    ll end = n - 1;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (s[i] != '1')
        {
            end = i;
            break;
        }
    }
    ll start = 0;
    for (ll i = 0; i <= end; i++)
    {
        ll j = i;
        bool val = false;
        while (s[j] == '1' && j<=end)
        {
            j++;
            val = true;
        }
        if(val){
            operations++;
            p.push_back(make_pair(i+1, j-i));
        }
        i = j;
        // start = j + 1;
    }
    cout << operations << endl;
    for (auto i : p)
    {
        cout << i.first << " " << i.second << endl;
    }

    // cout << "0" << endl;
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