// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
#define ll int long long
public:
    vector<string> ans;
    void permute(ll l, ll r, string S)
    {
        if (l == r)
        {
            ans.push_back(S);
        }
        else
        {
            for (int i = l; i <= r; i++)
            {
                swap(S[l], S[i]);
                permute(l + 1, r, S);
                swap(S[l], S[i]);
            }
        }
    }

    vector<string> find_permutation(string S)
    {
        // Code here there
        permute(0, S.length() - 1, S);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends