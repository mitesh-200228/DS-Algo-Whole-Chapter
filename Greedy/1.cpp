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
 
bool func(std::pair<ll,ll> p1,std::pair<ll,ll> p2){
    return p1.second < p2.second;
}

void solve(){
    ll n;cin>>n;
    std::vector<pair<ll,ll>> v(n);
    std::vector<ll> start(n);
    std::vector<ll> end(n);
    for(ll i=0;i<n;i++){
        cin>>start[i];
    }
    for(ll i=0;i<n;i++){
        cin>>end[i];   
    }
    for(ll i=0;i<n;i++){
        v[i].first = start[i];
        v[i].second = end[i];
    }
    std::sort(v.begin(),v.end(),func);
    ll c = 1;
    ll x = v[0].second;
    for(ll i=0;i<n-1;i++){
        if(x < v[i+1].first){
            c++;
            x = v[i+1].second;
        }
    }
    cout<<c<<endl;
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