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

bool iscycle(int src,vector<vector<ll>> &adj,vector<bool> &visited,vector<ll> &stack){
    stack[src] = true;
    if(!visited[src]){
        visited[src] = true;
        for(auto i : adj[src]){
            if(!visited[i] and iscycle(i,adj,visited,stack)){
                return true;
            }
            if(stack[i]){
                return true;
            }
        }
    }
    stack[src] = false; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;cin>>n>>m;
    std::vector<vector<ll>> adj(n);
    for(ll i=0; i<n ;i++){
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);
        // adj[b].push_back(a);   
    }
    bool cycle = false;
    vector<ll> stack(n,0);
    vector<bool> visited(n,0);
    for(ll i=0; i<n ;i++){
        if(!visited[i] and iscycle(i,adj,visited,stack)){
            cycle = true;
        }   
    }
    return 0;
}



// #include<iostream>
// #include<vector>
// #define ll int long long
// using namespace std;

// bool iscycle(ll src,vector<vector<ll>> &adj,vector<bool> &visited,vector<ll> &stack){
//     stack[src] = true;
//     if(!visited[src]){
//         visited[src] = true;

//         for(auto i:adj[src]){
//             if(!visited[i] && iscycle(i,adj,visited,stack)){
//                 return true;
//             }
//             if(stack[src]){
//                 return true;
//             }
//         }
//     }
//     stack[src] = false;
//     return false;
// }

// int32_t main(){
//     ll n,m;cin>>n>>m;
//     std::vector<vector<ll>> adj(n);
//     std::vector<ll> stack(n,0);
//     std::vector<bool> visited(n,false);
    
//     for(ll i=0; i<n ;i++){
//         ll u,v;cin>>u>>v;
//         adj[u].push_back(v);
//     }
//     ll x = 1;
//     for(ll i=0; i<n ;i++){
//         if(!visited[i] && iscycle(i,adj,visited,stack)){
//             cout<<"Cycle is Present"<<endl;
//             x = 0;
//         }
//     }
//     if(x) cout<<"Cycle is not Present!!"<<endl;
//     return 0;
// }