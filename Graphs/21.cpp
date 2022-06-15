#include<bits/stdc++.h>
#define ll int long long
using namespace std;
const ll INF = 10e9;

int32_t main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> edges;
    for(ll j=0;j<m;j++){
        ll u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});   
    }
    ll src;cin>>src;
    vector<ll> dist(n,INF);
    dist[src] = 0;
    for(ll i=0;i<n-1;i++){
        for(auto e : edges){
            ll u = e[0];
            ll v = e[1];
            ll w = e[2];
            dist[v] = min(dist[v],w+dist[u]);
            // cout<<dist[v]<<" ";
        }cout<<endl;
    }
    for(auto i:dist){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}