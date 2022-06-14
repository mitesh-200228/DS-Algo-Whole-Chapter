#include<bits/stdc++.h>
using namespace std;
const int inf = 1e7;

int32_t main(){
	int n,m;cin>>n>>m;
	std::vector<int> dist(n+1,inf);
	std::vector<std::vector<std::pair<int,int>>> graph(1+n);
	for(int j=0;j<m;j++){
		int u,v,w;cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});	
	}
	int source;cin>>source;
	dist[source] = 0;
	std::set<std::pair<int,int>> s;
	s.insert({0,source});
	while(!s.empty()){
		auto x = *(s.begin());
		s.erase(x);
		for(auto i:graph[x.second]){
			if(dist[i.first] > dist[x.second] + i.second){
				s.erase({dist[i.first],i.first});
				dist[i.first] = dist[x.second] + i.second;
				s.insert({dist[i.first],i.first});
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dist[i]<inf){
			cout<<dist[i]<<" ";
		}else{
			cout<<"-1"<<endl;
		}
	}	
	return 0;
}