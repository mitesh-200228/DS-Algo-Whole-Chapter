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
 
void print(vector<ll> v,ll n){
    for(ll i=0;i<n;i++){
        cout<<v[i]<<' ';
    }cout<<endl;
}
 
void solve(){
    string s;cin>>s;
    vector<ll> v(s.length());
    for(ll i=0;i<s.length();i++){
        cin>>v[i];
    }
    ll n = s.length();
    map<char,vector<ll>> ans;
    ll i;
    for(i=0;i<n-1;i++){
        if(s[i] == s[i+1]){
            ans[s[i]].push_back(v[i]);
        }
        if(s[i] != s[i+1] && s[i]==s[i-1]){
            ans[s[i]].push_back(v[i]);
        }
    }
    if(i==n-1){
        if(s[i]==s[i-1]){
            ans[s[i]].push_back(v[i]);
        }
    }
    ll cnt = 0;
    ll an = 0;
    for(auto it:ans){
        ll k = INT_MIN;
        ll sum = 0;
        for(ll i=0;i<it.second.size();i++){
            sum += it.second[i];
            k = max(k,it.second[i]);
        }
        an += sum - k;
        cnt++;
    }
    cout<<an<<endl;
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