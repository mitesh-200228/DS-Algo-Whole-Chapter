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
ll k = INT_MAX;

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

ll MxMn(vector<vector<ll>> &dp,vector<ll> v,ll n,ll i,ll j){
    if(i>=j){
        return 0;
    }
    else if((v[j]-v[i])<=k){
        return 0;
    }
    else if(dp[i][j]!=-1){
        return dp[i][j];
    }else if((v[j]-v[i])>k){
        dp[i][j] = 1 + min(MxMn(dp,v,n,i+1,j),MxMn(dp,v,n,i,j-1));
    }
    return dp[i][j];
}

void solve(){
    ll n;cin>>n;
    cin>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<ll>> dp(n,vector<ll> (n,-1));
    cout<<MxMn(dp,v,n,0,n-1);
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