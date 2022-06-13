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
    std::queue<ll> q;
    q.push(1);
    ll n;cin>>n;
    ll m;cin>>m;
    cout<<"Want Bipetrate ? Give and as 1 or 0";
    ll bip;
    cin>>bip;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        if(bip){
            adj[y].push_back(x);   
        }
    }
    q.push(1);
    while(!q.empty()){
        ll ptr = q.front();
        q.pop();
        cout<<ptr<<" ";
        vis[ptr] = true;
        std::vector<ll>::iterator it;
        for(it=adj[ptr].begin();it!=adj[ptr].end();it++){
            if(!vis[*it]){
                vis[*it] = true;
                q.push(*it);
            }
        }
    }
    return 0;
}