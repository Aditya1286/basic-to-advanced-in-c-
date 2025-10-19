#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> vis;
        string ans = s;
        q.push(s);
        vis.insert(s);
        int n = s.size();

        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            ans = min(ans, cur);

            string t = cur;
            for (int i = 1; i < n; i += 2) {
                t[i] = (t[i] - '0' + a) % 10 + '0';
            }
            if (!vis.count(t)) {
                vis.insert(t);
                q.push(t);
            }

            string r = cur.substr(n - b) + cur.substr(0, n - b);
            if (!vis.count(r)) {
                vis.insert(r);
                q.push(r);
            }
        }

        return ans;
    }
};
