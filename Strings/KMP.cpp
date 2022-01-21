#include<unordered_set>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
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
 
std::vector<ll> prefix_sum(string s,ll n){
    std::vector<ll> pi(n,0);
    for(ll i=1;i<n;i++){
        ll j = pi[i-1];
        while(j>0 and s[i]!=s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

void solve(){
    ll n;cin>>n;
    string s;cin>>s;
    string t;cin>>t;
    std::vector<ll> res = prefix_sum(s,n);
    ll pos = -1;
    ll i(0),j(0);
    while(i<s.size()){
        if(s[i] == t[j]){
            i++;j++;
        }else{
            if(j!=0){
                j = res[j-1];
            }else{
                i++;
            }
        }
        if(j == t.size()){
            pos = i - t.size();
            break;
        }
    }
    cout<<pos<<endl;
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