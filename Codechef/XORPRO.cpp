#include <bits/stdc++.h>
using namespace std;
#define ar array
#define int long long
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << " " << x << endl;
#define print(v)     \
    for (auto x : v) \
        cout << x << " ";
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const int M = 1e9 + 7;
const int N = 1e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        x ^= a[i];
    }
    int ans = 1e16;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, abs(a[i] - (x ^ a[i])));
    }
    cout << ans << endl;
}

signed main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
