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
const ll n = 12;
using namespace std;
std::vector<bool> dp(n+1,false);
std::vector<string> words(n);
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

bool exist(string s){
    ll n = words.size();
    for(ll i=0;i<n;i++){
        if(words[i] == s){
            return true;
        }
    }
    return false;
}

bool problemSolve(string A){
    if(A.size() == 0){
        return true;
    }
    ll n = A.length();
    for(ll i=1;i<=n;i++){
        if(!dp[i] && exist(A.substr(0,i)) ){
            dp[i] = true;
        }
        if(dp[i]){
            if(i==A.length()) return true;
            for(ll j=1+i;j<=n;j++){
                if(!dp[j] && exist(A.substr(i,j-i))){
                    dp[j] = true;
                }
                if(j==A.length() && dp[j]) return true;
            }
        }
    }
    return false;
}

void solve(){
    string A;
    cin>>A;
    for(ll i=0;i<n;i++){
        cin>>words[i];
    }
    ll sz = A.length();
    cout<<problemSolve(A);
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