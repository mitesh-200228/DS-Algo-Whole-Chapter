#include <bits/stdc++.h>
using namespace std;
#define MOD 10000000007
#define ll int long long
class Solution{
public:
int M = 1e9 + 7;
    int nCr(int n, int r){
        vector<int> dp(r + 1, 0); dp[0] = 1;
       for(int i = 1; i <= n; i++)
           for(int j = r; j > 0; j--)
               dp[j] = (dp[j] % M + dp[j - 1] % M) % M;
       return dp[r];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends