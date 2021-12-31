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
ll dp[10005]; 
ll ans(ll n,ll p,ll q,ll r){
    ll a = INT_MIN;
    ll b = INT_MIN;
    ll c = INT_MIN;

    if(n == 0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    if(p<=n){
        a = ans(n-p,p,q,r);
    }
    if(q<=n){
        b = ans(n-q,p,q,r);
    }
    if(r<=n){
        c = ans(n-r,p,q,r);
    }
    return dp[n] = 1+max(a,max(b,c));
}

void solve(){
    ll n;cin>>n;
    memset(dp,-1,sizeof(dp));
    ll p,q,r;
    cin>>p>>q>>r;
    ans(n,p,q,r);
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