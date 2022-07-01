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

string func(string S){
    string t = "";
    std::unordered_map<char, int> mp;
    std::priority_queue<std::pair<int, char>> pq;

    for (auto s : S)
        mp[s] += 1;

    for (auto m : mp)
        pq.push(make_pair(m.second, m.first));

    while (pq.size() > 1)
    {
        auto top1 = pq.top();
        pq.pop();
        auto top2 = pq.top();
        pq.pop();

        t += top1.second;
        t += top2.second;

        top1.first -= 1;
        top2.first -= 1;

        if (top1.first > 0)
            pq.push(top1);

        if (top2.first > 0)
            pq.push(top2);
    }

    if (!pq.empty())
    {
        if (pq.top().first > 1)
            return "";

        else
            t += pq.top().second;
    }

    return t;
}

void solve()
{
    string s;
    cin >> s;
    cout << func(s);
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