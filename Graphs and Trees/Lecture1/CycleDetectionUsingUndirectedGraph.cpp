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
vector<ll> parent(N);
vector<ll> sz(N);

void makeedge(ll v){
    parent[v] = v;
    sz[v] = 1;
}
ll find_set(ll v){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}
void union_sets(ll a,ll b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sz[a] < sz[b]){
            swap(a,b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  
    for(ll i=0; i<N ;i++){
        makeedge(i);
    }
  
    ll n,m;
    cin>>n>>m;
    std::vector<vector<ll>> adj(n);
    std::vector<bool> visited(n,false);
    for(ll i=0;i<n;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll cycle = 0;
    for(auto i : adj){
        ll u = i[0];
        ll v = i[1];
        ll x = find_set(u);
        ll y = find_set(v);
        if(x == y) cycle = 1;
        else union_sets(u,v);
    }
    if (!cycle)
    {
        cout<<"Not Contain Cycle"<<endl;/* code */
    }else{
        cout<<"Contains Cycle"<<endl;
    }
    
    return 0;
}