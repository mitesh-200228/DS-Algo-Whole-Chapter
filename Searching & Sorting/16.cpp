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
 
// best for finding power of a^b in O(logn)
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
    std::vector<ll> pref(n);
    std::vector<ll> ans(n);
    std::vector<ll> sufx(n);
    pref[0] = v[0];
    sufx[n-1] = v[n-1];
    for(ll i=1; i<n ;i++){
        pref[i] = pref[i-1]*v[i];  
        // cout<<pref[i]<<" "; 
    }cout<<endl;
    for(ll i=n-2; i>=0 ;i--){
        sufx[i] = sufx[i+1]*v[i];
    }
    for(ll i=0; i<n ;i++){
        if(i==0){
            ans[i] = sufx[1];
            // cout<<sufx[0]<<endl;
        }else if(n==i+1){
            ans[i] = pref[n-2];
        }else{
            ans[i] = pref[i-1]*sufx[i+1];
        }
    }
    for(ll i=0; i<n ;i++){
        cout<<ans[i]<<" ";   
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