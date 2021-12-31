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
#include<list>
#include<cmath>
#include<math.h>
#include<limits>
 
#define ll long long int
const ll N = 1e5+ 2,MOD = 1e9+7;
using namespace std;

class graph{
    public:
    int v;
    std::list<int> *arr;

    graph(int v){
        this->v = v;
        this->arr = new std::list<int>[this->v];
    }

    void add_edge(int u,int v,bool bidir = true){
        this->arr[u].push_back(v);
        if(bidir){
            this->arr[v].push_back(u);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll v;
    cin>>v;

    std::vector<std::list<int>> graph;
    graph.resize(v,std::list<int>());
    ll e;
    cin>>e;

    while(e--){
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    return 0;
}