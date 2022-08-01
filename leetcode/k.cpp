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
 
vector<ll> solver(vector<string> v,ll n){
    vector<ll> arr;
    for(ll i=0;i<n;i++){
        arr.push_back(stoi(v[i].substr(0)));
    }
    return arr;
}

void solve(){
    ll n;cin>>n;
    vector<string> v(n);
    ll dif;cin>>dif;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll> ans = solver(v,n);
    ll a = INT_MAX;
    ll b = INT_MIN;
    unordered_map<ll,ll> mp;
    vector<ll> M;
    for(ll i=0;i<n;i++){
        mp[ans[i]]++;
        if(i==0){
            M.push_back(0);
            continue;
        }
        if(ans[i]<=0){
            mp[ans[i]]--;
            if(!mp[ans[i]]){
                if(ans[i] == a){
                    a = INT_MAX;
                }else if(ans[i]==b){
                    b = INT_MIN;
                }
                mp.erase(ans[i]);
            }
        }
        if(mp.find(ans[i] - dif) != mp.end() || mp.find(a-b)!=mp.end()){
            M.push_back(1);
            a = ans[i];
            b = dif;
        }else{
            M.push_back(0);
        }
    }
    print(M,n);
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