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
 
bool compare(pair<ll,ll> p1,pair<ll,ll> p2){
    double v1 = (double) p1.first / p1.second;
    double v2 = (double) p2.first / p2.second;
    return v1 > v2;
}

void solve(){
    ll n;cin>>n;
    ll w;cin>>w;
    std::vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;   
    }
    std::sort(v.begin(),v.end(),compare);
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(w >= v[i].second){
            ans += v[i].first;
            w = w - v[i].second;
            continue;
        }
        double vw = (double) v[i].first / v[i].second;
        ans += vw*w;
        w = 0;
        break;    
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