#include <bits/stdc++.h>
using namespace std;
#define ll int long long
class Solution
{
public:
    int findMaxSum(int *arr, int n){
        int dp[n];
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for (int i = 2; i < n; i++){
            dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}