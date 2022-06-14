#include <bits/stdc++.h>
using namespace std;

std::vector<std::unordered_set<int>> make_graph(int numTasks,std::vector<std::pair<int, int>> &prerequisites){
    std::vector<std::unordered_set<int>> graph(numTasks);
    for (auto pre : prerequisites)
        graph[pre.second].insert(pre.first);
    return graph;
}

bool dfs_cycle(vector<unordered_set<int>> &graph, int node,vector<bool> &onpath, vector<bool> &visited){
    if (visited[node])
        return false;
    onpath[node] = visited[node] = true;
    for (int neigh : graph[node])
        if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
            return true;
    return onpath[node] = false;
}

bool canFinish(int numTasks, vector<pair<int, int>> &prerequisites){
    std::vector<std::unordered_set<int>> graph = make_graph(numTasks, prerequisites);
    std::vector<bool> onpath(numTasks, false), visited(numTasks, false);
    
    for (int i = 0; i < numTasks; i++)
        if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
            return false;
    return true;
}

int main()
{
    int numTasks = 4;
    std::vector<std::pair<int, int>> prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 1));
    prerequisites.push_back(make_pair(3, 2));
    if (canFinish(numTasks, prerequisites)){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}
