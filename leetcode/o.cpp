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

bool checker(ll i,ll j,ll m){
    if(i<0 || j<0 || i>=2 || j>=m){
        return 0;
    }
    return 1;
}

ll solver(vector<vector<ll>> matrix,ll &dp[][],ll m,ll i,ll j){
    ll u,v,w,x;
    if(matrix[i+1][j] <= matrix[i][j] + 1 && checker(i+1,j,m)){
        u = matrix[i+1][j] - matrix[i][j];
    }
    if(matrix[i][j+1] <= matrix[i][j] + 1 && checker(i,j+1,m)){
        v = matrix[i][1+j] - matrix[i][j];
    }
    if(matrix[i][j-1] <= matrix[i][j] + 1 && checker(i,j-1,m)){
        w = matrix[i][j-1] - matrix[i][j];
    }
    if(matrix[i-1][j] <= matrix[i][j] + 1 && checker(i-1,j,m)){
        x = matrix[i+1][j] - matrix[i][j];
    }
    return dp[i][j] = solver(matrix,dp,m,i+1,j) + solver(matrix,dp,m,i,j+1) + solver(matrix,dp,m,i-1,j) + solver(matrix,dp,m,i,j-1);
}

void solve(){
    ll m;cin>>m;
    vector<vector<ll>> matrix(2,vector<ll> (m,0));
    for(ll i=0;i<2;i++){
        for(ll j=0;j<m;j++){
            cin>>matrix[i][j];
        }   
    }
    ll dp[2][m];
    memset(dp,-1,sizeof(dp));
    solver(matrix,dp,m,0,0);
    cout<<dp[2][m]<<endl;
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