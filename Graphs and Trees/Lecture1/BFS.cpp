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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(ll i=0;i<N;i++){
        vis[i] = false;
    }
    int n,m;cin>>n>>m;
    ll x,y;
    for(ll i=0;i<n;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    std::queue<ll> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        cout<<node<<endl;
        vector<ll>::iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++){
            if(!vis[*it]){
                vis[*it] = true;
                q.push(*it);
            }
        }
    }
    return 0;
}