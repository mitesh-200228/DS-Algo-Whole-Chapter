#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 1e5 + 2, MOD = 1e9 + 7;

bool vis[N];
std::vector<ll> adj[N];

bool detectCycle(ll src,ll parent){
    vis[src] = true;
    for(auto it:adj[src]){
        if(parent!=it){
            if(vis[it]) return true;
            if(!vis[it] && detectCycle(it,src)) return true;
        }
    }
    return false;
}

int main()
{
    for (ll i = 0; i < N; i++)
    {
        vis[i] = false;
    }
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool cycle = false;
    for(ll i=0;i<n;i++){
        if(!vis[i] && detectCycle(i,-1)){
            cycle = true;
            break;
        }
    }
    if(cycle) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}