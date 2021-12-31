#include <unordered_set>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <queue>
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

// best for finding power of a^b in O(logn)
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
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // ll ans = INT_MIN;
    ll z = 0;
    std::vector<ll>::iterator low1, low2, low3;
    // for (ll i = 0; i < n - 2; i++)
    // {
    //     for (ll j = i + 2; j < n; j++)
    //     {
    //         ll x = i + j;
    //         ll i1 = ((v[j] - v[(x) / 2]) * (v[(x) / 2] - v[i]));
    //         ll i2 = ((v[j] - v[((x) / 2) - 1]) * (v[((x) / 2) - 1] - v[i]));
    //         ll i3 = ((v[j] - v[((x) / 2) + 1]) * (v[((x) / 2) + 1] - v[i]));

    //         z += max(max(i2, i3), i1);
    //         // cout<<z<<" "<<i<<" "<<j<<endl;
    //     }
    // }
    // cout << z << endl;
    ll ans;
    for(ll i=0; i<n-2 ;i++){
        for(ll j=i+2; j<n ;j++){
            ll mid = v[i] + (v[j]-v[i])/2; 
            low1 = lower_bound(v.begin(),v.end(),mid+1);  
            // cout<<(low1-v.begin())<<endl;
            z = (v[j] - v[low1-v.begin()])*(v[low1-v.begin()] - v[i]);
            cout<<z<<endl;
        }
    }   cout<<endl;
    cout<<z<<endl;
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