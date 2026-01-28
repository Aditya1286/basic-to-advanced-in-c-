class Solution {
private:
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adj, stack<int> &st) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, visited, adj, st);
            }
        }
        st.push(node);
    }

    void dfs3(int node, vector<int> &visited, vector<vector<int>> &adj) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs3(it, visited, adj);
            }
        }
    }

public:
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        stack<int> st;
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }

        vector<vector<int>> reverseadj(V);
        for (int i = 0; i < V; i++) {
            visited[i] = 0;
            for (auto it : adj[i]) {
                reverseadj[it].push_back(i);
            }
        }

        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                scc++;
                dfs3(node, visited, reverseadj);
            }
        }
        return scc;
    }
};
