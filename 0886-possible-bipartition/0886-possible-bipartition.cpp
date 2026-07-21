class Solution {
private:

    bool dfs(int node, int color,
             vector<vector<int>>& adj,
             vector<int>& visited) {

        visited[node] = color;

        for (auto nodi : adj[node]) {

            if (visited[nodi] == -1) {

                if (!dfs(nodi, !color, adj, visited))
                    return false;
            }

            else if (visited[nodi] == color) {
                return false;
            }
        }

        return true;
    }

public:

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n + 1);

        for (auto it : dislikes) {

            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n + 1, -1);

        for (int i = 1; i <= n; i++) {

            if (visited[i] == -1) {

                if (!dfs(i, 0, adj, visited))
                    return false;
            }
        }

        return true;
    }
};