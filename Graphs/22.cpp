#include<bits/stdc++.h>
#define ll int long long
using namespace std;
const ll INF = 10e9;

int32_t main(){
    vector<vector<ll>> graph = {{0,5,INF,10},{INF,0,3,INF},{INF,INF,0,1},{INF,INF,INF,0}};
    ll n = graph.size();
    vector<vector<ll>> dist = graph;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            for(ll k=0;k<n;k++){
                dist[j][k] = min(dist[j][k],dist[j][i] + dist[i][k]);
            }   
        }   
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(dist[i][j] == INF)
                cout<<"INT ";
            else
                cout<<dist[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}