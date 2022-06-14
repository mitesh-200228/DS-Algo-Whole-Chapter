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
using namespace std;
const ll N = 1e5+ 2,MOD = 1e9+7;
const ll n = 4,m = 2;
std::vector<std::vector<ll>> visited(n,vector<ll>(m,0));

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

bool isSafe(vector<vector<ll>> v,ll i,ll j,vector<vector<ll>> &visited){
    if(i>=0 && i<n && j>=0 && j<m){
        return true;
    }
    return false;
}

void FindNumberOfIslands(vector<vector<ll>> v,ll i,ll j){
    visited[i][j] = 1;
    ll x[] = {-1,-1,0,1,1,1,0,-1};
    ll y[] = {0,1,1,1,0,-1,-1,-1};
    for(ll k=0;k<8;k++){
       ll nx = i + x[k];
       ll ny = i + y[k];
       if(isSafe(v,nx,ny,visited) && !visited[nx][ny] && v[nx][ny]){
        FindNumberOfIslands(v,nx,ny);
       } 
    }   
}

void solve(){
    vector<vector<ll>> v(n,vector<ll>(m,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    ll ilands = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(!visited[i][j] && v[i][j]==1){
                FindNumberOfIslands(v,i,j);
                ilands++;
            }   
        }   
    }
    cout<<ilands<<endl;
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