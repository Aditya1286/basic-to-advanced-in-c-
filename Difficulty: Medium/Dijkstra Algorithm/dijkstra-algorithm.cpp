class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > dist[node]) continue;

            for (auto it : adj[node]) {
                int adjn = it.first;
                int edgwt = it.second;

                if (d + edgwt < dist[adjn]) {
                    dist[adjn] = d + edgwt;
                    pq.push({dist[adjn], adjn});
                }
            }
        }

        return dist;
    }
};
