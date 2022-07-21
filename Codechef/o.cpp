#include <bits/stdc++.h>
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
    ll yu1 = 0;
    for (int i = 0; i < b.length(); i++)
    {
        yu1 = ((yu1 * 10) + (b[i] - '0')) % a;
    }
    return __gcd(a, yu1);
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n,0);
    multiset<ll> st;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        st.insert(v[i]);
    }
    ll yu1 = 1, yu = 1;
    while (st.size()){
        auto it = st.lower_bound(yu);
        if (it != st.end()){
            st.erase(it);
            yu++;
        }
        else{
            yu = 1;
            yu1++;
        }
    }
    cout << yu1 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}