#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& colors) {
        colors[node] = color;
        for (auto it : graph[node]) {
            if (colors[it] == -1) {
                if (!dfs(it, !color, graph, colors))
                    return false;
            } 
            else if (colors[it] == color) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> colors(V, -1);

        for (int i = 0; i < V; i++) {
            if (colors[i] == -1) {
                if (!dfs(i, 0, graph, colors))
                    return false;
            }
        }
        return true;
    }
};
