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
    ll x,y;cin>>x>>y;
    std::vector<ll> ind(x,0);
    for(ll i=0; i<x ;i++){
        vis[i] = false;
    }
    for(ll i=0; i<x ;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        ind[b]++;
    }
    queue<ll> pq;
    for(ll i=0; i<x ;i++){
        if(ind[i] == 0){
            pq.push(i);
        }   
    }
    ll cnt = 0;
    while(!pq.empty()){
        cnt++;
        ll x = pq.front();
        pq.pop();
        cout<<x<<" ";
        for(auto it:adj[x]){
            ind[it]--;
            if(ind[it] == 0){
                pq.push(it);
            }
        }
    }

    return 0;
}