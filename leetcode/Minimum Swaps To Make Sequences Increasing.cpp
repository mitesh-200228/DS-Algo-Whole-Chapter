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
    ll n;cin>>n;
    vector<ll> v1(n,0);
    vector<ll> v2(n,0);
    for(ll i=0;i<n;i++){
        cin>>v1[i];
    }
    for(ll i=0;i<n;i++){
        cin>>v2[i];   
    }
    vector<ll> swaps(n,0);
    vector<ll> no_swap(n,0);
    for(ll i=1;i<n;i++){
        if(v1[i]>v1[i-1] && v2[i]>v2[i-1]){
            swaps[i] = swaps[i-1] + 1;
            no_swap[i] = no_swap[i-1];
        }   
        if(v1[i]>v2[i-1] && v1[i-1]<v2[i]){
            swaps[i] = min(swaps[i],1 + no_swap[i-1]);
            no_swap[i] = min(no_swap[i],swaps[i-1]);
        }
    }
    cout<<min(swaps[n-1],no_swap[n-1]);
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