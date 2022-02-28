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
#include <bits/stdc++.h>
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
    string s;
    cin>>s;
    vector<ll> v(4);
    ll n = s.size();
    for(ll i=0;i<n;i++){
        if(s[i] == 'C') v[0]++;
        if(s[i] == 'H' and v[1] < v[0]) v[1] += 1;
        if(s[i] == 'E' and v[2] < v[1]) v[2] += 1;
        if(s[i] == 'F' and v[3] < v[2] ) v[3] += 1;
    }
    cout<<v[3]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}