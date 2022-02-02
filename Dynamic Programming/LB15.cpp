#include<unordered_set>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<cstring>
#include<algorithm>
#include<queue>
#include <stdio.h>
#include<stack>
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
 
void solve(){
    string x;cin>>x;
    string y;cin>>y;
    std::vector<vector<ll>> dp(2,vector<ll> (y.length() + 1));
    ll bi = 0;
    ll n = x.length();
    ll m = y.length();
    for(ll i=0;i<=n;i++){
        bi = i&1;
        for(ll j=0;j<=m;j++){
            if( i == 0 || j == 0){
                dp[bi][j] = 0;
            }else if(x[i-1] == y[j-1]){
                dp[bi][j] = 1 + dp[1-bi][j- 1];
            }else{
                dp[bi][j] = max(dp[1-bi][j],dp[bi][j- 1]);
            }
        }  
    }
    cout<<dp[bi][m]<<endl;
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