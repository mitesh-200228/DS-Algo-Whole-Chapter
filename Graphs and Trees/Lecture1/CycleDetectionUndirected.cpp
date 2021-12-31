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
bool vis[N];

bool iscycle(ll src,std::vector<vector<ll>> &adj,std::vector<bool> &visited,ll parent){
    visited[src] = true;
    for(auto i:adj[src]){
        if(i != parent){
            if(visited[i]) return true;
            if(!visited[i] and iscycle(i,adj,visited,src)){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n,m;cin>>n>>m;
    std::vector<vector<ll>> adj(n);
    for(ll i=0; i<n ;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);   
    }   
    bool cycle = false;
    vector<bool> visited(n,false);
    for(ll i=0; i<n ;i++){
        if(!visited[i] && iscycle(i,adj,visited,-1)){
            cycle = true;
        }   
    }
    if(cycle) cout<<"Cycle is Present";
    else cout<<"Not present";
    return 0;
}