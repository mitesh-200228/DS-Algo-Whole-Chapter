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
    ll a, b;
    cin >> a >> b;
    std::vector<ll> answer(a,0);
    std::set<pair<ll, ll>, std::greater<std::pair<ll, ll>>> p, q;
    std::vector<ll> xt(a + 1, a);
    for (ll i = 0; i <= b-1; i++){
        ll c, d;
        cin >> c >> d;
        if (xt[c] > d){
            xt[c] = d;
        }
    }
    for (ll i = 1; i < a+1; i++){
        p.insert({xt[i], i});
        ll ss = -1;
    }
    for (ll i = a - 1; i >= 0; i--){
        while (!p.empty() && p.begin()->first - 1 == i){
            ll v = p.begin()->second;
            p.erase(p.begin());
            q.insert({v, xt[v]});
        }
        if (q.empty()){
            cout << -1 << endl;
            return;
        }
        ll v = q.begin()->first;
        q.erase(q.begin());
        answer[i] = v;
    }
    for (int i = 0; i <= a - 1; i++){
        cout << answer[i] << " ";
    }
    cout << endl;
}

int main()
{
    ll te;
    cin >> te;
    for (int io = 0; io < te; io++)
    {
        solve();
    }
    return 0;
}