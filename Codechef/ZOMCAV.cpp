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
    std::vector<ll> C(n+1, 0);
    std::vector<ll> H(n+1, 0);
    std::map<ll,ll> m;
    for (ll i = 0; i < n; i++)
    {
        cin >> C[i+1];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> H[i+1];
        m[H[i+1]]++;
    }
    std::map<ll,ll> radiation;
    std::map<ll,ll> r2;
    for (ll i = 1; i <= n; i++)
    {
        ll x = 1;
        while ((x <= i + C[i]) && (x<=n))
        {
            radiation[x]++;
            x++;
        }
    }
    for(ll i=1;i<=n;i++){
        r2[radiation[i]]++;
    }
    for(auto it:r2){
        if(m.find(it.first) == m.end()){
            cout<<"NO"<<endl;
            return;
        }else{
            if(it.second != m[it.first]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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