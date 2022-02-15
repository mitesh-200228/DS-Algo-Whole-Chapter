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
    ll n;cin>>n;
    std::vector<ll> v(n);
    ll ans = INT_MIN;
    ll ans1 = INT_MAX;
    for(ll i=0;i<n;i++){
        cin>>v[i];   
    }
    for(ll i=0;i<n;i++){
        ans = max(ans,v[i]);
        ans1 = min(ans1,v[i]);
    }
    ll store;
    ll store1;
    for(ll i=0;i<n;i++){
        if(ans == v[i]){
            store = i;
        }   
        if(ans1 == v[i]){
            store1 = i;
        }
    }
    // cout<<store<<" "<<store1<<endl;
    if(store < store1) {
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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