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
    ll x,y;
    cin>>x>>y;
    ll z = x^y;
    ll a=0,b=0,c=0;
    // cout<<z<<endl;
    if(z%2 == 0){
        // a = 1,c = 1;
        bool xy = false;
        ll n = ceil(log2(z));
        for(ll i=0;i<n;i++){
            if(((1<<i)&z)){
                if(xy){
                    c |= (1<<i);
                    xy = false;
                }else{
                    a |= (1<<i);
                    xy = true;
                }
            }else{
                c |= (1<<i);
                a |= (1<<i);
            }
        }
        b = y^c;
        vector<ll> ans;
        ans.push_back(a);
        ans.push_back(b);
        ans.push_back(c);
        sort(ans.begin(),ans.end());
        print(ans,3);
        // cout<<min(a,min(b,c))<<" "<< 
        // cout<<a<<" "<<b<<" "<<c<<endl;
    }
    else if(x%2 == 0){
        a = 1,b = 1;
        bool xy = false;
        ll n = ceil(log2(x));
        for(ll i=0;i<n;i++){
            if(((1<<i)&x)){
                if(xy){
                    b |= (1<<i);
                    xy = false;
                }else{
                    a |= (1<<i);
                    xy = true;
                }
            }else{
                b |= (1<<i);
                a |= (1<<i);
            }
        }
        c = z^a;
        vector<ll> ans;
        // cout<<a<<" "<<b<<" "<<c<<endl;
        ans.push_back(a);
        ans.push_back(b);
        ans.push_back(c);
        sort(ans.begin(),ans.end());
        print(ans,3);
    }
    else if(y%2 == 0){
        b = 1,c = 1;
        bool xy = false;
        ll n = ceil(log2(y));
        for(ll i=0;i<n;i++){
            if(((1<<i)&y)){
                if(xy){
                    c |= (1<<i);
                    xy = false;
                }else{
                    b |= (1<<i);
                    xy = true;
                }
            }else{
                b |= (1<<i);
                c |= (1<<i);
            }
        }
        a = x^b;
        vector<ll> ans;
        ans.push_back(a);
        ans.push_back(b);
        ans.push_back(c);
        sort(ans.begin(),ans.end());
        print(ans,3);
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