#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 1e5 + 2, MOD = 1e9 + 7;

bool vis[N];
std::vector<ll> adj[N];

void dfs(ll ptr){
    vis[ptr] = true;
    for (auto it : adj[ptr]){
        if (!vis[it]){
            dfs(it);
        }
    }
    return;
}

int main()
{
    for (ll i = 0; i < N; i++){
        vis[i] = false;
    }
    ll n;cin >> n;
    ll m;cin >> m;
    for (ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll count = 0;
    for (ll i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i);
            count++;
        }
    }
    cout << count - 1 << endl;
    return 0;
}