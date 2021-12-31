// https://www.codechef.com/problems/FGFS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long int
#define endl "\n"

using namespace std;

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

ll activity_sel(vector<pair<ll, ll>> &v)
{
    sort(v.begin(), v.end(), cmp);
    pair<ll, ll> last = v[0];
    ll cnt = 1;
    for (int i = 1; i < v.size(); i++) 
    {
        if (v[i].first >= last.second)
        {
            ++cnt;
            last = v[i];
        }
    }
    return cnt;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        map<ll, vector<pair<ll, ll>>> mp;
        for (ll i = 0; i < n; i++)
        {
            ll s, f, p;
            cin >> s >> f >> p;
            mp[p].push_back({s, f});
        }
        ll c = 0;
        for (auto i : mp)
            c += activity_sel(i.second);

        cout << c << endl;
    }
    return 0;
}