#include<unordered_set>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stdio.h>
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

ll dp[51][51][51];

ll dfs(ll m,ll n,ll maxMove,ll startRow,ll startColumn){
    if(startRow<0 || startRow>=m || startColumn<0 || startColumn>=n){
        return 1;
    }
    if(maxMove<=0){
        return 0;
    }
    if(dp[startRow][startColumn][maxMove]!=-1){
        return dp[startRow][startColumn][maxMove];
    }
    ll down = dfs(m,n,maxMove-1,startRow+1,startColumn);
    ll right = dfs(m,n,maxMove-1,startRow,startColumn+1);
    ll up = dfs(m,n,maxMove-1,startRow-1,startColumn);
    ll left = dfs(m,n,maxMove-1,startRow,startColumn-1);
    dp[startRow][startColumn][maxMove] = (down%MOD + up%MOD + left%MOD + right%MOD)%MOD;
    return dp[startRow][startColumn][maxMove];
}

void solve(){
    ll m;cin>>m;
    ll n;cin>>n;
    ll maxMove;cin>>maxMove;
    ll startRow;cin>>startRow;
    ll startColumn;cin>>startColumn;
    memset(dp,-1,sizeof(dp));
    cout<<dfs(m,n,maxMove,startRow,startColumn);
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