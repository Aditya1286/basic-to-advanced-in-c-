#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b){ return a[2] < b[2]; });

        vector<char> knows(n, false);
        knows[0] = true;
        knows[firstPerson] = true; // secret shared at time 0

        vector<vector<int>> adj(n);            // temporary adjacency for current time-group
        vector<char> involved(n, false);      // mark nodes involved in current time-group

        int m = meetings.size();
        int i = 0;
        while (i < m) {
            int t = meetings[i][2];
            int j = i;

            // build graph for meetings with time == t
            vector<int> nodes; // list of distinct nodes involved this time
            while (j < m && meetings[j][2] == t) {
                int x = meetings[j][0], y = meetings[j][1];
                adj[x].push_back(y);
                adj[y].push_back(x);
                if (!involved[x]) { involved[x] = true; nodes.push_back(x); }
                if (!involved[y]) { involved[y] = true; nodes.push_back(y); }
                ++j;
            }

            // For each connected component, check if any already knows secret
            vector<char> seen(n, false);
            for (int start : nodes) {
                if (seen[start]) continue;
                // BFS/DFS to collect component
                queue<int> q;
                vector<int> comp;
                q.push(start);
                seen[start] = true;
                bool anyKnown = false;

                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    comp.push_back(u);
                    if (knows[u]) anyKnown = true;
                    for (int v : adj[u]) {
                        if (!seen[v]) {
                            seen[v] = true;
                            q.push(v);
                        }
                    }
                }

                // If any member already knew the secret, mark whole component
                if (anyKnown) {
                    for (int u : comp) knows[u] = true;
                }
            }

            // clear temporary structures for next time
            for (int u : nodes) {
                adj[u].clear();
                involved[u] = false;
            }

            i = j;
        }

        vector<int> result;
        for (int p = 0; p < n; ++p) if (knows[p]) result.push_back(p);
        return result;
    }
};
