#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, tin, tout, subxor;
    vector<pair<int,int>> edges;
    int timer = 0;

    void dfs(int u, int p, const vector<int>& nums) {
        parent[u] = p;
        depth[u] = (p == -1 ? 0 : depth[p] + 1);
        tin[u] = timer++;
        subxor[u] = nums[u];
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, nums);
            subxor[u] ^= subxor[v];
        }
        tout[u] = timer++;
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& inputEdges) {
        n = nums.size();
        adj.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        subxor.assign(n, 0);
        edges.clear();

        for (auto& e : inputEdges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges.emplace_back(u, v);
        }

        dfs(0, -1, nums);
        int totalXor = subxor[0];
        int ans = INT_MAX;

        for (int i = 0; i < n - 1; i++) {
            int u1 = edges[i].first, v1 = edges[i].second;
            if (parent[v1] != u1) swap(u1, v1);
            for (int j = i + 1; j < n - 1; j++) {
                int u2 = edges[j].first, v2 = edges[j].second;
                if (parent[v2] != u2) swap(u2, v2);

                int x1, x2, x3;
                if (isAncestor(v1, v2)) {
                    x1 = subxor[v2];
                    x2 = subxor[v1] ^ subxor[v2];
                    x3 = totalXor ^ subxor[v1];
                } else if (isAncestor(v2, v1)) {
                    x1 = subxor[v1];
                    x2 = subxor[v2] ^ subxor[v1];
                    x3 = totalXor ^ subxor[v2];
                } else {
                    x1 = subxor[v1];
                    x2 = subxor[v2];
                    x3 = totalXor ^ subxor[v1] ^ subxor[v2];
                }

                int mx = max({x1, x2, x3});
                int mn = min({x1, x2, x3});
                ans = min(ans, mx - mn);
            }
        }

        return ans;
    }
};
