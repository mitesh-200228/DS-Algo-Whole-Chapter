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
#include<bits/stdc++.h>
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
    ll n;cin>>n;
    ll key;cin>>key;
    std::vector<ll> v(n);
    std::vector<ll> ans(2*n);
    if(key > 1){
        ll j = n;
        ll sum0 = 0;
        for(ll i=0;i<n;i++){
            cin>>v[i];
            sum0 += v[i];
            ans[i] = v[i];
            ans[i+j] = v[i];
        }
        ll ans1 = INT_MIN;
        ll sum = 0;
        for(ll i=0;i<2*n;i++){
            sum+=ans[i];
            ans1=max(ans1,sum);
            if(sum<0){
                sum = 0;
            }   
        }
        // cout<<sum<<" "<<sum0<<endl;
        cout<<max(ans1 + sum0*(key-2),ans1)<<endl;
    }else{
        for(ll i=0;i<n;i++){
            cin>>v[i];
        }
        ll ans = INT_MIN;
        ll sum = 0;
        for(ll i=0;i<n;i++){
            sum+=v[i];
            ans=max(ans,sum);
            if(sum<0){
                sum = 0;
            }   
        }
        cout<<ans<<endl;
    }
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