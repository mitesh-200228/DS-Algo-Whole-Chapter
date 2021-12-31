// https://codeforces.com/contest/276/problem/C

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
    ll q;cin>>q;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll> pref(n,0);
    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;
        r-=1;
        pref[l] += 1;
        if(r+1<n) pref[r+1]--;
    }
    for(ll i=1; i<n ;i++){
        pref[i]+=pref[i-1];
    }
    sort(v.begin(),v.end());
    sort(pref.begin(),pref.end());

    ll ans = 0;
    for(ll i=0; i<n ;i++){
        ans+= (v[i]*pref[i]);
    }   
    cout<<ans<<endl;
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