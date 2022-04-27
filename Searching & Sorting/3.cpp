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
    vector<ll> nums(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    ll target;
    cin >> target;
    int high = nums.size() - 1;
    int low = 0;
    int mid = low + (high - low) / 2;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[low] <= nums[mid])
        {
            if (target <= nums[mid] && target >= nums[low])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (target >= nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return;
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