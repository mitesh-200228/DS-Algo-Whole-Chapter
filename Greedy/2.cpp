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

struct Job
{
    char id;
    ll dead;
    ll profit;
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void solve()
{
    Job v[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    ll n = sizeof(v)/sizeof(v[0]);
    std::sort(v, v + n, comparison);
    ll result[n];
    bool slot[n];
    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (ll i = 0; i < n; i++){
        for (ll j = min(n, v[i].dead) - 1; j >= 0; j--){
            if (slot[j] == false){
                result[j] = i;  
                slot[j] = true; 
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << v[result[i]].id << " ";
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