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
std::vector<ll> powers(N);
 
ll calculate_hash(string s){
    ll hash = 0;
    ll n = s.size();
    for(ll i=0;i<n;i++){
        hash = (hash + (s[i]-'a' + 1)*powers[i])%MOD;
    }
    return hash;    
}

void solve(){
    ll p = 31;
    powers[0] = 1;
    std::vector<string> strings = {"aa","ab","a","b","bb","ba","cc","ca","ac"}; 
    for(ll i=1;i<N;i++){
        powers[i] = (powers[i-1]*2)%MOD;
    }
    std::vector<ll> hashes;
    for(auto i:strings){
        hashes.push_back(calculate_hash(i));
    }
    sort(hashes.begin(),hashes.end());
    ll distinct = 0;
    for(ll i=0;i<hashes.size();i++){
        if(i == 0 || hashes[i] != hashes[i-1]){
            distinct++;
        }
    }
    cout<<distinct<<endl;
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