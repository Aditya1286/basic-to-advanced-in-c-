class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto it : prerequisites) {
            int course = it[0];
            int prerequisite = it[1];

            adj[prerequisite].push_back(course);
        }

        for (int i = 0; i < n; i++) {
            for (int node : adj[i]) {
                indegree[node]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            count++;

            for (int node : adj[current]) {
                indegree[node]--;

                if (indegree[node] == 0) {
                    q.push(node);
                }
            }
        }

        return count == n;
    }
};