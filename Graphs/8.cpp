#include <bits/stdc++.h>
#define ll int long long
const ll N = 10e5 + 2;
using namespace std;

bool isValid(vector<vector<ll>> &v,ll i,ll j,ll n,ll m){
    if(i>=0 && i<n && j>=0 && j<m && v[i][j] && v[i][j]!='$'){
        return true;
    }
    return false;
}

void floodFill(std::vector<std::vector<ll>> &v,ll sr,ll sc,ll n,ll m,std::vector<std::vector<bool>> visited){
    visited[sr][sc] = true;
    ll dx[] = {-1,0,1,0};
    ll dy[] = {0,1,0,-1};
    for(ll i=0;i<4;i++){
        ll nx = sr + dx[i];
        ll ny = sc + dy[i];
        if(isValid(v,nx,ny,n,m) && !visited[nx][ny]){
            v[nx][ny] = '$';
            floodFill(v,nx,ny,n,m,visited);
        }
    }
}

int main(){
    ll n;cin>>n;
    ll m;cin>>m;
    std::vector<std::vector<ll>> v(n,std::vector<ll> (m,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>v[i][j];   
        }   
    }
    ll sr,sc;
    cin>>sr>>sc;
    std::vector<vector<bool>> visited(n,std::vector<bool> (m,false));
    floodFill(v,sr,sc,n,m,visited);
    v[sr][sc] = '$';
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<v[i][j]<<" ";   
        }   cout<<endl;
    }
    return 0;
}