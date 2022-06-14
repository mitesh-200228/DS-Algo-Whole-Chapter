#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 1e5 + 2, MOD = 1e9 + 7;

bool vis[N];
std::vector<ll> adj[N];
ll inDegree[N];
ll jobs[N];

void dfs(ll ptr){
    vis[ptr] = true;
    cout << ptr << "->";
    for (auto it : adj[ptr]){
        if (!vis[it])
            dfs(it);
    }
}

void jobsQ(ll numberOfJobs){
    queue<ll> q;
    for(ll i=0;i<numberOfJobs;i++){
        if(inDegree[i] == 0){
            jobs[i]++;
            q.push(i);
        }
    }
    while(!q.empty()){
        ll x = q.front();
        q.pop();
        for(auto it:adj[x]){
            // cout<<it<<"---";
            inDegree[it]--;
            if(inDegree[it] == 0){
                q.push(it);
                jobs[it] = jobs[x] + 1;
            }
        }
    }
    for(ll it=0;it<numberOfJobs;it++){
        cout<<jobs[it]<<" ";
    }
}

int main(){
    for (ll i = 0; i < N; i++){
        vis[i] = false;
    }
    ll n;cin >> n;
    ll m;cin >> m;
    for (ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        inDegree[y]++;
    }
    ll numberOfJobs = n;

    jobsQ(numberOfJobs);
    // dfs(1);
    return 0;
}