#include<unordered_set>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
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
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }

    ll idx = -1;
    for(ll i=n-1;i>0;i--){
        if(v[i]>v[i-1]){
            idx = i;break;
        }
    }
    if(idx == -1){
        reverse(v.begin(),v.end());
    }
    else{
        ll prev = idx;
        cout<<prev<<endl;
        for(ll i=idx+1;i<n;i++){
            if(v[i]>v[idx-1] && v[i]<=v[prev]){
                prev = i;
            }
        }
        cout<<v[prev]<<endl;
        swap(v[idx-1],v[prev]);
        reverse(v.begin()+idx,v.end());
    }
    for(ll i=0;i<n;i++){
        cout<<v[i]<<" ";   
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