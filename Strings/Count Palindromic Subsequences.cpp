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
#include<cstring>
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
 
int solvefinal(string s,int a,int b,int dp) {
    if(a>b){
        return 0;
    }   
    if(a==b) return 1;
    if(dp[a][b]!=-1){
        return dp[a][b];
    }
    if(s[a] == s[b]) return dp[a][b] = solvefinal(s,a+1,b,dp) + solvefinal(s,a,b-1,dp) + 1;
    else{
        dp[a][b] = return solvefinal(s,a+1,b,dp) + solvefinal(s,a,b-1,dp) - solvefinal(s,a+1,b-1,dp);
    }
}

void solve(){
    int n;cin>>n;
    string s;cin>>s;

    int dp[1001][1001];
    memset(dp, -1, sizeof(dp));
    cout<<solvefinal(s,0,n-1,dp);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}