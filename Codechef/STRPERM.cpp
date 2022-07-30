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
    for(ll i=1;i<n;i++){
        cout<<v[i]<<' ';
    }cout<<endl;
}
 
void solve(){
    ll n;cin>>n;
    ll m;cin>>m;
    std::vector<ll> nums(n+1,1);
    vector<vector<ll>> idx(n+1,vector<ll> ());
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;   
        idx[y].push_back(x);
        nums[x] = 0;
    }
    for(ll i=1;i<=n;i++){
        if(nums[i]){
            idx[n].push_back(i);
        } 
    }
    priority_queue<ll> pq;
    vector<ll> ans(1+n);
    for(ll i=n;i>=1;i--){
        for(ll num:idx[i]){
            pq.push(num);
        }
        if(pq.empty()){
            cout<<"-1"<<endl;
            return;
        }
        ans[i] = pq.top();
        // cout<<pq.top()<<" ";
        pq.pop();
    }       
    print(ans,n+1);
    // cout<<endl;
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