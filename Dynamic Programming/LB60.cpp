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
 
bool cmp(vector<ll> v1,vector<ll> v2){
    if(v1[1] == v2[1]) return v1[0]<v2[0];
    return v1[1] < v2[1];
}

//I Didn't use DP cause it is not effiecient solutions
//It takes more than O(n^2) + O(nlogn) 

void solve(){
    ll n;cin>>n;
    vector<vector<ll>> v(n,vector<ll> (2,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<2;j++){
            cin>>v[i][j];
        }
    }
    std::sort(v.begin(),v.end(),cmp);
    ll ans = 1;
    ll curr = v[0][1];
    for(ll i=0;i<n;i++){
        if(curr<v[i][0]){
            ans++;
            curr = v[i][1];
        }  
    }
    cout<<ans<<endl;
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