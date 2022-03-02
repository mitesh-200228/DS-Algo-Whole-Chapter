#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define mod 1000000007
#define gcd(a, b) __gcd(a, b)
bool bit(ll a, ll j)
{
    ll newno = a >> (j - 1);
    return newno & 1;
}
void solve()
{

    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll b[n][30];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < 30; j++)
        {
            if (bit(a[i], j + 1))
            {
                b[i][j] = 1;
            }
            else
            {
                b[i][j] = 0;
            }
        }
    }
    ll count = 0, sum = 0;
    for (ll i = 0; i < 30; i++)
    {
        count = 0;
        for (ll j = 0; j < n; j++)
        {
            // cout<<b[j][i];
            if (b[j][i] == 1)
                count++;
        }
        count = (count * (count - 1)) / 2;
        // cout<<count;
        sum = sum + ((1 << i) * count);
        // cout<<endl;
    }
    cout << sum;
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}