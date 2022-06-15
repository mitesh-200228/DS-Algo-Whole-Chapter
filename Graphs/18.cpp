#include<bits/stdc++.h>
#define ll int long long
using namespace std;
const ll N = 1e5+6;

std::vector<ll> parent(N);
std::vector<ll> sz(N);

void make_set(ll v){
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
		if(sz[a]<sz[b]){
			swap(a,b);
		}
		parent[b] = a;
		sz[a] += sz[b];
	}
}

int32_t main(){
	for(ll i=0;i<N;i++){
		make_set(i);
	}
	int n,m;
	cin>>n>>m;
	vector<vector<ll>> graph;
	for(ll i=0;i<m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		graph.push_back({w,u,v});
	}
	sort(graph.begin(),graph.end());
	ll cost = 0;
	for(auto it:graph){
		ll w = it[0];
		ll u = it[1];
		ll v = it[2]; 
		ll x = find_set(u);
		ll y = find_set(v);
		if(x == y){
			continue;
		}else{
			cout<<u<<" "<<v<<endl;
			cost += w;
			union_sets(u,v);
		}
	}
	cout<<cost<<endl;
	return 0;
}