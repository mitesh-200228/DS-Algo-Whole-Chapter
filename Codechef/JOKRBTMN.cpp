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
    ll l;cin>>l;
    std::unordered_map<ll,ll> mp;
    ll p = 1;
    while(m--){
        ll x;cin>>x;
        std::vector<ll> v(x);
        for(ll i=0;i<x;i++){
            cin>>v[i];   
        }
        for(ll i=0;i<x;i++){
            mp[v[i]] = p;
        }
        ++p;
    }
    std::vector<ll> s(l);
    for(ll i=0;i<l;i++){
        cin>>s[i];
    }
    ll cnt = 1;
    ll i = 0;
    // for(auto it:mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    while(i<l-1){
        if(mp[s[i]] == mp[s[i+1]]){
            i++;
        }else{
            cnt++;
            i++;
        }
    }
    cout<<cnt<<endl;
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