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

ll x[] = {-2,-1,1,2,2,1,-1,-2};
ll y[] = {1,2,2,1,-1,-2,-2,-1}; 

double dp[26][26][101];

double solveit(ll n,ll k,ll row,ll column){
    if(k==0){
        return 1;
    }
    if(row>=n || column>=n || row<0 || column<0){
        return 0;
    }
    if(dp[row][column][k]){
        return dp[row][column][k];
    }
    double sum = 0;
    for(ll i=0;i<8;i++){
        sum += solveit(n,k-1,row+x[i],column+y[i]);
    } 
    sum/=8;
    return dp[row][column][k] = sum;
}

void solve(){
    ll n;cin>>n;
    ll k;cin>>k;
    ll row,column;cin>>row>>column;
    memset(dp,0,sizeof(dp));
    cout<<solveit(n,k,row,column);
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