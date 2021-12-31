#include<unordered_set>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
#include<queue>
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
std::vector<bool> visited;
std::vector<ll> col;
bool bipart = true;

void color(ll u,std::vector<vector<ll>> &adj,ll cur){
    if(col[u]!=-1 && col[u]!=cur){
        bipart = false;
        return;
    }
    col[u] = cur;
    if(visited[u]) return;
    visited[u] = true;
    for(auto i: adj[u]){
        color(i,adj,cur^1);
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;cin>>n>>m;
    std::vector<vector<ll>> adj(n);
    visited = std::vector<bool>(n,false);
    col = std::vector<ll>(n,-1);
    for(ll i=0; i<n ;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);   
    }
    for(ll i=0; i<n ;i++){
        if(!visited[i]){
            color(i,adj,0);
        }   
    }
    if(bipart) cout<<"Graph is Biparted"<<endl;
    else cout<<"Not Bipartted"<<endl;
    return 0;
}