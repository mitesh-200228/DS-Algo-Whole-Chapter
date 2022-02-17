// https://codeforces.com/contest/1638/problem/A
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
    ll mn = INT_MAX;
    ll mx = INT_MIN;
    unordered_map<ll,ll> ump;
    for(ll i=1;i<=n;i++){
        cin>>v[i];
        ump[v[i]] = i;
    }
    ll a = 1;
    ll startPnt = 1;
    ll endPnt = n;
    if(n == 1){
        cout<<v[1]<<endl;
        return;
    }
    for(ll i=1;i<=n;i++){
        if(v[i]!=i){
            for(auto i:ump){
                if(i.first == a){
                    endPnt = i.second;
                    break;
                }
            }
        }else{  
            startPnt++;
            a++;
        }
    }   
    for(ll i=startPnt;i<=endPnt;i++){
        swap(v[i],v[n-i]);
    }
    for(ll i=1;i<=n;i++){
        cout<<v[i]<<" ";   
    }cout<<endl;
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