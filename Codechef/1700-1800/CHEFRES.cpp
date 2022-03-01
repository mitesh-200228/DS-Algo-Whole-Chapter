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
    ll m;cin>>m;
    std::vector<std::pair<ll,ll>> p(n);
    std::vector<ll> v(m);
    std::vector<ll> ans(10e9,0);
    ll j = n;
    while(j) {
        ll a,b;cin>>a;cin>>b;
        for(ll i=a;i<=b;i++){
            ans[i] = 1;
        }
        j--;
    }
    ll k = m;
    while(k--) {
        ll x;cin>>x;
        if(ans[x] && ans[x+1]){
            cout<<"0"<<endl;
            continue;
        }else if(ans[x] && !ans[x+1]){
            ll p = x;
            while(!ans[p]){
                p++;
            }
            if(p<10e9) {
                cout<<abs(p-x+1)<<endl;
            }else{
                cout<<"-1"<<endl;
            }
        }
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