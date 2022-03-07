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
    vector<ll> v(n);
    ll x = 0;
    ll mn = INT_MAX;
    ll mx = INT_MIN;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        mn = min(mn,v[i]);
        mx = max(mx,v[i]);
    }
    bool isSorted = is_sorted(v.begin(),v.end());
    // cout<<isSorted<<"---";
    string s;
    cin>>s;
    ll N = 0,S=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='N') N++;
        else S++;
    }
    if(N==n || S==n){
        cout<<"-1"<<endl;
        return;
    }
    if(isSorted){
        cout<<"0"<<endl;
        return;
    }
    if(s[0]!=s[n-1] && isSorted){
        cout<<"0"<<endl;
        return;
    }
    if(s[0]!=s[n-1] && !isSorted){
        cout<<"1"<<endl;
        return;
    }
    if(v[0]==mn){
        s.erase(0,1);
        n--;
    }
    if(v[n-1]==mx){
        s.pop_back();
        n--;
    }
    ll pos2 = n-1;
    ll pos1 = 1;
    if(s[0]==s[n-1]){
        cout<<s[0]<<" "
        cout<<"2"<<endl;
        return;
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