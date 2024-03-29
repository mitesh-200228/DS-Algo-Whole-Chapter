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
 
void print(vector<ll> v,ll n){
    for(ll i=0;i<n;i++){
        cout<<v[i]<<' ';
    }cout<<endl;
}
 
void solve(){
    ll n;cin>>n;
    ll m;cin>>m;
    ll dp[n+1][1+m];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = 1;
    // dp[1][0] = 1;
    std::vector<std::vector<ll>> matrix(n,std::vector<ll> (m,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>matrix[i][j];   
        }   
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(!matrix[i-1][j-1]){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }      
    }
    cout<<dp[n][m]<<endl;
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