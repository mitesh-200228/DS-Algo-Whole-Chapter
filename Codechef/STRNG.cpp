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

bool check(std::vector<ll> v,ll n){
    bool flag = true;
    for (ll i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            flag = false;
            break;
        }
    }
    return flag;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll primeCnt = 0;
    ll start = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll gcd = __gcd(v[0], v[1]);
    vector<ll> gcds(n,0);
    vector<ll> gcde(n,0);
    gcds[0] = v[0];
    gcde[n-1] = v[n-1];
    for(ll i=1;i<n;i++){
        gcds[i] = __gcd(v[i],gcds[i-1]);
        gcde[n-1-i] = __gcd(v[n-1-i],gcde[n-i]);
        if(i>1){
            gcd = __gcd(v[i], gcd);
        }
    }
    ll cnt = 0;
    for(ll i=0;i<n;i++){
        if(i==0){
            if(gcde[i+1] == gcd && gcd>1){
                cnt++;
                // cout<<"a1 ";
            }else if(gcde[i+1] != gcd && gcd>1){
                cnt++;
                // cout<<"b1 ";
            }else if(gcde[i+1] != gcd && gcd==1){
                cnt++;
                // cout<<"c1 ";
            }
        }else if(i == n-1){
            if(gcds[i-1] == gcd && gcd>1){
                cnt++;
                // cout<<"a2 ";
            }else if(gcds[i-1] != gcd && gcd>1){
                cnt++;
                // cout<<"b2 ";
            }else if(gcds[i-1] != gcd && gcd==1){
                cnt++;
                // cout<<"c2 ";
            }
        }else{
            if(__gcd(gcds[i-1],gcde[i+1]) == gcd && gcd>1){
                cnt++;
                // cout<<"a3 ";
            }else if(__gcd(gcds[i-1],gcde[i+1]) != gcd && gcd>1){
                cnt++;
                // cout<<"b3 ";
            }else if(__gcd(gcds[i-1],gcde[i+1]) != gcd && gcd==1){
                cnt++;
                // cout<<"c3 ";
            }
        }
    }
    cout << cnt << endl;
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