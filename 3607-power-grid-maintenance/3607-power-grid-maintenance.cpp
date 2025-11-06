#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> parent(c + 1), size(c + 1);
        vector<set<int>> comp(c + 1);
        vector<int> res;
        vector<bool> online(c + 1, true);

        iota(parent.begin(), parent.end(), 0);
        fill(size.begin(), size.end(), 1);
        for (int i = 1; i <= c; i++) comp[i].insert(i);

        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return;
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            if (comp[b].size() > comp[a].size()) comp[a].swap(comp[b]);
            for (int x : comp[b]) comp[a].insert(x);
            comp[b].clear();
        };

        for (auto &e : connections) unite(e[0], e[1]);

        for (auto &q : queries) {
            int t = q[0], x = q[1];
            int root = find(x);

            if (t == 2) {
                if (online[x]) {
                    online[x] = false;
                    comp[root].erase(x);
                }
            } else {
                if (online[x]) res.push_back(x);
                else {
                    if (comp[root].empty()) res.push_back(-1);
                    else res.push_back(*comp[root].begin());
                }
            }
        }
        return res;
    }
};
