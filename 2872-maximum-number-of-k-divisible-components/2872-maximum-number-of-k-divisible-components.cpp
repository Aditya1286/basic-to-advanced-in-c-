#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if (k == 0) return 0; // undefined divisibility by 0; problem constraints usually have k >= 1

        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        // Build parent and order (preorder) using iterative stack, then reverse for postorder.
        vector<int> parent(n, -1);
        vector<int> order; order.reserve(n);
        stack<int> st;
        st.push(0);
        parent[0] = -2; // mark root's parent as visited sentinel
        while (!st.empty()) {
            int u = st.top(); st.pop();
            order.push_back(u);
            for (int v : g[u]) {
                if (parent[v] == -1) {
                    parent[v] = u;
                    st.push(v);
                }
            }
        }

        reverse(order.begin(), order.end()); // process children before parent
        vector<long long> subsum(n, 0);
        for (int u : order) {
            subsum[u] += values[u];
            for (int v : g[u]) {
                if (parent[v] == u) subsum[u] += subsum[v];
            }
        }

        auto mod = [&](long long x)->int {
            int r = int(x % k);
            if (r < 0) r += k;
            return r;
        };

        if (mod(subsum[0]) != 0) return 0; // total not divisible -> no valid split

        int cuts = 0;
        for (int i = 1; i < n; ++i) {
            if (mod(subsum[i]) == 0) ++cuts;
        }
        return cuts + 1; // components = cuts + 1
    }
};
