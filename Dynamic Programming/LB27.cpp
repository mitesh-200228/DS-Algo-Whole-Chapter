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
 
void MaxPathSum(std::vector<std::vector<ll>> v,ll n){
    vector<vector<ll>> dp(n,vector<ll> (n,-1));
    ll ans = 0;
    for(ll i=n-2;i>=0;i--){
        for(ll j=0;j<n;j++){
            ll a = (j==0 || i==n-1) ? 0:v[i+1][j-1];
            ll b = (j==n-1 || i==n-1) ? 0:v[i+1][1+j];
            ll c = (i==n-1) ? 0:v[i+1][j];
            v[i][j] = max(a,max(b,c)) + v[i][j];
        }   
    }
    ll ma=INT_MIN;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            ma=max(ma,v[i][j]);
        }
    }
    cout<<ma<<endl;
}

void solve(){
    ll n;cin>>n;
    vector<vector<ll>> v(n,vector<ll> (n,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    MaxPathSum(v,n);
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