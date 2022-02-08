#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[201][201];
    int solve(int n, int k)
    {
        if (n == 1)
        {
            return k;
        }
        if (k == 0)
        {
            return 0;
        }
        if (dp[n][k] != -1)
        {
            return dp[n][k];
        }
        int ans = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            int breakegg = solve(n - 1, i - 1);
            int notbreak = solve(n, k - i);
            int ans1 = max(breakegg, notbreak);
            ans = min(ans, ans1 + 1);
        }
        return dp[n][k] = ans;
    }
    int eggDrop(int n, int k)
    {
        memset(dp, -1, sizeof(dp));
        int x = solve(n, k);
        return x;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}