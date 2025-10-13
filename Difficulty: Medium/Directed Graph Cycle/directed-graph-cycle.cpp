class Solution {
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited) {
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (dfs(it, adj, visited, pathVisited)) return true;
            } else if (pathVisited[it]) {
                return true;
            }
        }
        
        pathVisited[node] = 0;
        return false;
    }
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, pathVisited)) return true;
            }
        }
        return false;
    }
};
