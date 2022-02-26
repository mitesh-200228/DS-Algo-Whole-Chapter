#include<unordered_set>
#include<stack>
#include<vector>
#include<iostream>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> v(n);
        for(ll i=0;i<n;i++){
            cin>>v[i];   
        }
        vector<ll> dp(n + 1, -1LL * 1e12);

        for (int i = 0; i < n; i++)
        {
            ll val = 0;
            for (int j = i; j < n; j++)
            {
                val += v[j];
                dp[j - i + 1] = max(dp[j - i + 1], val);
            }
        }

        for (ll i = 0; i <= n; i++)
        {
            ll ans = 0;
            for (ll j = 1; j <= n; j++)
            {
                ans = max(ans, dp[j] + (min(i, j) * x));
            }
            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}