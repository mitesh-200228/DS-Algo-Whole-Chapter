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

bool func(std::pair<ll, ll> a, std::pair<ll, ll> b)
{
    if (a.first >= b.first)
        return true;
    return false;
}

void solve()
{
    ll n;
    cin >> n;
    ll x;
    cin >> x;
    std::vector<ll> v(n);
    std::vector<std::pair<ll, ll>> pr;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        pr.push_back(make_pair(v[i], i));
    }
    std::sort(pr.begin(), pr.end(), func);
    if (pr[0].first + pr[1].first <= x)
    {
        cout << "YES" << endl;
        return;
    }
    else
    {
        for(ll i=0;i+1<n;i++){
            if(pr[i].first + pr[i+1].first > x){
                if(pr[i].second < pr[i+1].second){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
        cout<<"YES"<<endl;
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