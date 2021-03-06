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
#define ld long double
const ll N = 1e5+ 2,MOD = 1e9+7;
ll m;
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

ld dist(ll x1,ll y1,ld x2,ld y2){
    ld ans = 0;
    ans = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    // cout<<ans<<endl;
    return ans;
}

void solve(){
    ll n;cin>>n;
    m = n;
    ll a,b,c;cin>>a>>b>>c;
    std::vector<std::pair<ll,ll>> coordinates;
    ll q = n;
    while(q--){
        ll a,b;cin>>a>>b;
        coordinates.push_back(make_pair(a,b));
    }
    ld l = -5000;
    ld r = 5000;
    while((r-l)>1e-8){
        ld mid1 = l + (r-l)/3;
        ld mid2 = r - (r-l)/3;
        ld dist1=0,dist2=0;
        for(ll i=0;i<n;i++){
            dist1 += dist(coordinates[i].first,coordinates[i].second,mid1,-(c+a*mid1)/b);
            dist2 += dist(coordinates[i].first,coordinates[i].second,mid2,-(c+a*mid2)/b);   
        }
        if(dist1>dist2){
            l = mid1;
        }
        else if(dist2>dist1){
            r = mid2;
        }
        else{
            l = mid1;
            r = mid2;
        }
    }
    ld ans = 0;
    for(ll i=0;i<n;i++){
        ans += dist(coordinates[i].first,coordinates[i].second,l,-(c+a*l)/b);   
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
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