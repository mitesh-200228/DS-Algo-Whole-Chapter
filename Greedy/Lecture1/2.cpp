/*
Given an unsorted list of integeres and number k , you have to perfom exactly k elements.
    Operation that you can do is :
        choose any integer a[i] and convert it to -a[i].

Find max sum of an array which can be achevied from this 
*/

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
    ll k;cin>>k;
    vector<ll> v(n);
    ll neg = 0;
    ll pos = 0;
    ll zero = 0;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        if(v[i]<0){
            neg++;
        }else if(v[i] == 0){
            zero++;
        }
        else{
            pos++;
        }
    }
    ll x = k%neg;
    sort(v.begin(),v.end());
    if(neg>=k){
        for(ll i=0;i<k;i++){
            v[i] = (-1)*v[i];
        }
    }else if(zero && neg>0 && neg<k){
        for(ll i=0;i<neg;i++){
            v[i] = (-1)*v[i];
        }
    }else{
        
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