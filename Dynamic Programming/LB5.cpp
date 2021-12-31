#include<unordered_set>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<map>
#include<unordered_map>
#include<set>
#include<climits>
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

ll dp[10001][10001];

void solve(){
    ll n;cin>>n;
    std::vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    
    for(ll i=1;i<n;i++){
        dp[i][i] = 0;
    }   

    for(ll l=2;l<n;l++){
        for(ll i=1;i<n-l+1;i++){
            ll j = i+l-1;
            dp[i][j] = MOD;
            for(ll k=i;k<j;k++){
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + v[i-1]*v[k]*v[j]);
            }
        }
    }
    cout<<dp[1][n-1];
}
 
int main()
{
    std::memset(dp,-1,sizeof dp);
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