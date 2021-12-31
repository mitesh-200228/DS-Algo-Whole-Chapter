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
std::vector<ll> adj[N];

void dfs(ll node){

    //preorder
    vis[node] = true;
    cout<<node<<" ";

    //inorder
    std::vector<ll>::iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(!vis[*it]){
            dfs(*it);
        }
    }
    //postorder
    // cout<<node<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n,m;cin>>n>>m;
    for(ll i=0; i<=n ;i++){
        vis[i] = false;   
    }
    
    for(ll i=0; i<n ;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);   
    }    

    dfs(1);

    return 0;
}