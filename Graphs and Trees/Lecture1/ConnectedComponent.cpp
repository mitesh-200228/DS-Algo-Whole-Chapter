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
std::vector<ll> components;
std::vector<bool> vis;

ll get_comp(ll idx,std::vector<vector<ll>> &adj){
    if(vis[idx]){
        return 0;
    }
    vis[idx] = true;
    ll ans = 1;
    for(auto i : adj[idx]){
        if(!vis[i]){
            ans += get_comp(i,adj);
            vis[i] = true;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n,m;cin>>n>>m;
    vector<vector<ll>> adj(n);
    vis = vector<bool>(n);    
    for(ll i=0; i<n ;i++){
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);   
    }
    for(ll i=0;i<n;i++){
        if(!vis[i]){
            components.push_back(get_comp(i,adj));
        }
    }
    for(auto i : components){
        cout<<i<<endl;
    } 
    return 0;
}