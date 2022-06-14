#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 1e5 + 2, MOD = 1e9 + 7;

bool vis[N];
std::vector<ll> adj[N];

void dfs(ll ptr)
{
    vis[ptr] = true;
    cout << ptr << "->";
    for (auto it : adj[ptr])
    {
        if (!vis[it])
            dfs(it);
    }
}
int main()
{
    for (ll i = 0; i < N; i++){
        vis[i] = false;
    }
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    vector<ll> inDegree(n,0);
    for (ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        inDegree[y]++;
    }
    queue<ll> pq;
    for(ll i=0;i<n;i++){
        if(inDegree[i] == 0){
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
            inDegree[it]--;
            if(inDegree[it] == 0){
                pq.push(it);
            }
        }
    }
    return 0;
}