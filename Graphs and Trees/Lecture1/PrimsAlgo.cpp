#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<iostream>
#define ll int long long
using namespace std;
ll n,m;
const ll N = 1e5+3;
std::vector<vector<ll,ll>> g[N];
ll cost = 0;
std::vector<ll> dist(N),parent(N);
std::vector<bool> visited(N);
const ll INF = 1e9;
void prismMST(ll source){
    for(ll i=1;i<n;i++){
        dist[i] = INF;
    }
    std::set<std::vector<ll>> s; 
    dist[source] = 0;
    s.insert({0,source});
    while(!s.empty()){
        auto x = *(s.begin());
        visited[x[1]] = true;
        ll u = x[1];
        ll v = parent[x[1]];
        ll w = x[0];
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost+=w;
        for(auto it:g[x[1]]){
            if(visited[it[0]]){
                continue;
            }
            if(dist[it[0]] > it[1]){
                s.erase({dist[it[0]],it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]],it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}

int32_t main(){
    cin>>n>>m;
    for(ll i=0; i<m;i++){
        ll u,v,w;   
        cin>>u>>v>>w;   
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    prismMST(0);
    return 0;
}