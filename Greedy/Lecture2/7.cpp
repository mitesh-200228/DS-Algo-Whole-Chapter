// You are given a ropes of diff lengths. we need to 
// merge them into one rope . cost of merge to ropes is 
// equal to sum of lenghts of that ropes . merge all ropes
// such that cost will becomes minimum

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
    sort(v.begin(),v.end());

    vector<ll> pref(n,0);
    pref[0] = v[0];
    for(ll i=1; i<n ;i++){
        pref[i] = v[i] + pref[i-1];   
        cout<<pref[i]<<" ";
    }
    cout<<endl;
    ll sum = 0;
    for(ll i=0; i<n ;i++){
        sum += pref[i];   
    }
    cout<<sum-pref[0]<<endl;
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