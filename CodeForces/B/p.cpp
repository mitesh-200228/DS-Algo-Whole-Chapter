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

ll FindAns(ll k,ll n, std::vector<ll> v, ll x, ll l, ll sum0, ll e, ll s)
{
    if (k <= l){
        if(sum0 < 0){
            sum0 = 0;
        }
        return sum0 + x * k;
    }
    else{
        if (s != 0 && e != n - 1){
            if ((k + v[s - 1] < 0) && (k + v[e + 1] < 0)){
                return sum0 + x * k;
            }
            else{
                ll ans = INT_MIN,ans2 = INT_MIN,sum1 = 0;
                ll sum = 0;
                v[s - 1] += x; 
                for (ll i = 0; i < n; i++){
                    sum += v[i];
                    ans = max(ans, sum);
                    if (sum < 0){
                        sum = 0;
                    }
                }
                v[s-1] -= x;
                v[e + 1] += x; 
                for (ll i = 0; i < n; i++){
                    sum1 += v[i];
                    ans2 = max(ans2, sum1);
                    if (sum1< 0){
                        sum1 = 0;
                    }
                }
                v[s - 1]+=x;
                ll finalAns = max(ans,ans2);
                return finalAns;
            }
        }
        else if (s != 0 && e == n - 1)
        {
            if ((k + v[s - 1] < 0))
            {
                return sum0 + x * k;
            }else{
                v[s-1] += x;
                ll ans3 = INT_MIN,sum3 = 0;
                for (ll i = 0; i < n; i++){
                    sum3 += v[i];
                    ans3 = max(ans3, sum3);
                    if (sum3 < 0){
                        sum3 = 0;
                    }
                }
                return ans3;
            }
        }
        else if (s == 0 && e != n - 1)
        {
            if ((k + v[e + 1] < 0))
            {
                return sum0 + x * k;
            }
            else{
                v[e+1] += x;
                ll ans4 = INT_MIN,sum4 = 0;
                for (ll i = 0; i < n; i++){
                    ans4 += v[i];
                    ans4 = max(sum4, ans4);
                    if (sum4 < 0){
                        sum4 = 0;
                    }
                }
                return ans4;
            }
        }
        else
        {
            return sum0 + x * k;
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    ll x;
    cin >> x;
    std::vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll length = 1;
    ll ans = INT_MIN;
    ll sum = 0;
    ll start = 0;
    ll end = 0;
    ll s = 0, e = 0;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] >= 0)
        {
            length++;
        }
        sum += v[i];
        if (sum > ans)
        {
            ans = sum;
            start = s;
            end = i;
        }
        if (sum < 0)
        {
            sum = 0;
            s = i + 1;
        }
    }
    ll f0 = ans;
    length = (end - start + 1);
    // if(f0< 0) f0 = 0;
    if(end == start) length = 0;
    // cout<<f0<<" "<<end<<" "<<start<<endl;
    for (ll i = 0; i <= n; i++)
    {
        cout << FindAns(i,n, v, x, length, f0, end, start) << " ";
    }
    cout << endl;
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