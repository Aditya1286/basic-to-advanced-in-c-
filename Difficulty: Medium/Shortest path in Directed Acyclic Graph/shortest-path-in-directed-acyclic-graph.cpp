class Solution {
  public:
    void topoSort(int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) topoSort(v, adj, vis, st);
        }
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges) {
        vector<pair<int,int>> adj[V];
        for (int i = 0; i < E; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) topoSort(i, adj, vis, st);
        }

        vector<int> dist(V, 1e9);
        dist[0] = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (dist[node] != 1e9) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) dist[v] = dist[node] + wt;
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};
