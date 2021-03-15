// 785. Is Graph Bipartite? (Medium)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        visited = vector<int> (V, -1);

        for (int i = 0; i < V; ++i){
            if (visited[i] == -1){
                if (!dfs(graph, i, 0))
                    return false;
            }
        }
        return true;
    }
private:
    vector<int> visited;
    bool dfs(vector<vector<int>>& graph, int s, int color){
        visited[s] = color;
        for(int x : graph[s]){
            if (visited[x] == -1){
                if (!dfs(graph, x, 1-color))
                    return false;
            }
            else if (visited[x] == color)
                return false;
        }
        return true;
    }

};