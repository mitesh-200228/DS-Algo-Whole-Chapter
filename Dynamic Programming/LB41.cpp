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

int dp[1001][1001];

ll lps(string &s1,string &s2,ll n1,ll n2){
    if(n1==0 || n2==0){
        return 0;
    }
    if(dp[n1][n2]!=-1){
        return dp[n1][n2];
    }
    if(s1[n1-1]==s2[n2-1]){
        return dp[n1][n2] = 1 + lps(s1,s2,n1-1,n2-1);
    }else{
        return dp[n1][n2] = max(lps(s1,s2,n1-1,n2),lps(s1,s2,n1,n2-1));
    }
}

void solve(){
    string s1;cin>>s1;
    string s2 = s1;
    std::reverse(s2.begin(),s2.end());
    ll n = s1.length();
    dp[n][n];
    memset(dp, -1, sizeof(dp));
    cout<<lps(s2,s1,n,n);
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