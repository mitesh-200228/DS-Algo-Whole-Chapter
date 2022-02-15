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
    vector<ll> v;
    ll zero = 0;
    unordered_map<ll,ll> ump;
    ll mini = INT_MAX;
    ll maxi = INT_MIN;
    for(ll i=0;i<2*n;i++){
        ll a;cin>>a;
        v.push_back(a);
        mini = min(mini,v[i]);
        maxi = max(maxi,v[i]);
    }
    ll cnta = 0;
    ll cntb = 0;
    for(auto it1:v){
        if(it1 == maxi) {
            cnta++;
        }
    }
    for(auto it2:v){
        if(it2 == mini){
            cntb++;
        }
    }
    if(mini<1){
        if(cnta%2 == 0 && cntb%2 == 0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else{
        cout<<"YES"<<endl;
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