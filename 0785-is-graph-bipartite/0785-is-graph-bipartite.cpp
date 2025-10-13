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
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (!dfs(i, 0, graph, colors))
                    return false;
            }
        }
        return true;
    }
};
