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
 
void print(std::vector<ll> v,ll n){
    for(ll i=0;i<n;i++){
        cout<<v[i]<<' ';
    }cout<<endl;
}
 
void solve(){
    string A,B,C;
    cin>>A>>B>>C;
    ll a = A.length();
    ll b = B.length();
    ll c = C.length();
    std::vector<std::vector<bool>> dp(A.size()+1,std::vector<bool> (B.size()+1,false));
    if(a+b!=c) {
        cout<<false<<endl;return;
    }
    for(ll i=0;i<=a;i++){
        for(ll j=0;j<=b;j++){
            if(i==0 && j==0){
                dp[i][j] = true;
            }
            else if(i==0 && j!=0){
                dp[i][j] = dp[i][j-1];
            }
            else if(i!=0 && j==0){
                dp[i][j] = dp[i-1][j];
            }
            else if(C[i+j-1]==A[i-1] && C[i-1+j]!=B[j-1]){
                dp[i][j] = dp[i-1][j];
            }
            else if(C[i+j-1]!=A[i-1] && C[i-1+j]==B[j-1]){
                dp[i][j] = dp[i][j-1];
            }else if(C[i+j-1]==A[i-1] && C[i+j-1]==B[j-1]){
                dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
            }
        }
    }
    cout<<dp[a][b]<<endl;
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