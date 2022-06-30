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
    ll sum = 0;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
        sum += v[i];
    }
    if(sum%2){
        cout<<"NO"<<endl;
        return;
    } 
    else sum/=2;
    std::vector<std::vector<bool>> dp(n+1,std::vector<bool> (sum+1,false));
    for(ll i=0;i<=n;i++){
        dp[i][0] = true;
    }
    for(ll i=0;i<=sum;i++){
        dp[0][i] = false;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=sum;j++){
            if(v[i-1]<=j){
                dp[i][j] = dp[i-1][j-v[i-1]] || dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }  
    }
    cout<<dp[n][sum]<<endl;
    // cout<<solve1(dp,v,sum,n-1);
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