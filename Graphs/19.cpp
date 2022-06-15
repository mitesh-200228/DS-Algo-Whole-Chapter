#include<bits/stdc++.h>
#define ll int long long
using namespace std;

ll n,m;
const ll N = 1e5+2;
vector<vector<ll>> g[N];
vector<bool> vis(N,false);
ll cost = 0;
vector<ll> dist(N),parent(N);

void primsMST(ll src){
    for(ll i=0;i<n;i++){
        dist[i] = INT_MAX;   
    }
    set<vector<ll>> s;
    dist[src] = 0;
    s.insert({0,src});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]] = true;
        ll u = x[1];
        ll v = parent[x[1]];
        ll w = x[0];
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost += w;
        for(auto it:g[x[1]]){
            if(vis[it[0]])
                continue;
            if(dist[it[0]] > it[1]){
                s.erase({dist[it[0]],it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]],it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
    // cout<<cost<<endl;
}

int32_t main(){
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }    
    primsMST(0);
    cout<<cost<<endl;
}
