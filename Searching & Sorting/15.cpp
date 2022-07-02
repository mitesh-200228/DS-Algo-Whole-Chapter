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
    unordered_map<ll,vector<ll>> m;
    vector<pair<ll,ll>> out;
    ll cnt = 0;
    ll sum = 0;
    for(ll i=0; i<n ;i++){
        sum += v[i];
        if(sum == 0){
            out.push_back(make_pair(0,i));
        }

        if(m.find(sum) != m.end()){
            vector<ll> vc = m[sum];
            for(auto it=vc.begin();it!=vc.end();it++){
                out.push_back(make_pair(1 + *it,i));
            }
        }
        m[sum].push_back(i);
    }
    for(auto it:out){
        cout<<it.first<<" "<<it.second<<endl;
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