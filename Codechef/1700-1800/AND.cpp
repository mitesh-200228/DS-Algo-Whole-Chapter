#include <bits/stdc++.h>
using namespace std;
#define ll int long long

void solve()
{
    ll n, i, ans = 0, j;
    cin >> n;
    ll a[n];
    vector<ll> v[32];
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if (a[i] & 1)
                v[j].push_back(1);
            a[i] /= 2;
        }
    }
    for (i = 0; i < 32; i++){
        ll p = v[i].size();
        ans += (p * (p - 1) / 2) * pow(2, i);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1; 
    while (t--){
        solve();
    }
}