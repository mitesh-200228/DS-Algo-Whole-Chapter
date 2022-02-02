#include<unordered_set>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<climits>
#include<cstring>
#include<cmath>
#include<math.h>
#include<limits>
#define ll long long int
const ll N = 1e5+ 2,MOD = 1e9+7;
using namespace std;
int power(ll a,ll b) {
    ll ans = 1;
    while(b>0){
        if(b%2){
            ans=ans*a;
        }
        a=a*a;b>>=1;
    }
    return ans;
}
ll countSetBits(ll n) {
    ll count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
 
ll gcd(ll a, string b){
    ll res = 0;
    for (int i = 0; i < b.length(); i++){
        res = ((res * 10) + (b[i] - '0')) % a;
    }
    return __gcd(a,res);
}

ll max1(ll x,ll y,ll z){
    return max(x,max(y,z));
}

void solve(){
    ll n;cin>>n;ll m;cin>>m;
    std::vector<vector<ll>> gold;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>gold[i][j];   
        }   
    }
    vector<vector<ll>> dp(n,vector<ll>(m,0));
    // memset(dp,0,sizeof(dp));

    for(ll col=m-1;col>=0;col--){
        for(ll row=0;row<=n-1;row++){
            ll right = (col == m-1) ? 0 : dp[row][col-1];
            ll up = (row == 0 || col == m-1) ? 0 : dp[row-1][col+1];
            ll down = (row == n-1 || col == m-1) ? 0 : dp[row+1][col+1];

            dp[row][col] = gold[row][col] + max1(right,up,down); 
        }
    }
    ll res = dp[0][0];
    for(ll i=1;i<m;i++){
        res = max(res,dp[i][0]);
    }
    cout<<res<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}