class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> rows, cols;
        for (auto &b : buildings) {
            rows[b[0]].push_back(b[1]);
            cols[b[1]].push_back(b[0]);
        }
        for (auto &p : rows) sort(p.second.begin(), p.second.end());
        for (auto &p : cols) sort(p.second.begin(), p.second.end());
        
        int ans = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            auto &r = rows[x];
            auto &c = cols[y];
            
            auto it = lower_bound(r.begin(), r.end(), y);
            bool left = (it != r.begin());
            bool right = (it + 1 != r.end());
            
            auto it2 = lower_bound(c.begin(), c.end(), x);
            bool up = (it2 != c.begin());
            bool down = (it2 + 1 != c.end());
            
            if (left && right && up && down) ans++;
        }
        return ans;
    }
};
