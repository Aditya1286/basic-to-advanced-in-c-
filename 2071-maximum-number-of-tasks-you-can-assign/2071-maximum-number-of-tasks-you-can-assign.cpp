class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto canAssign = [&](int mid) -> bool {
            int p = pills;
            multiset<int> ws;
            for (int i = m - mid; i < m; ++i) {
                ws.insert(workers[i]);
            }
            for (int i = mid - 1; i >= 0; --i) {
                auto it = prev(ws.end());
                if (*it >= tasks[i]) {
                    ws.erase(it);
                } else {
                    if (!p) return false;
                    auto rep = ws.lower_bound(tasks[i] - strength);
                    if (rep == ws.end()) return false;
                    --p;
                    ws.erase(rep);
                }
            }
            return true;
        };

        int left = 1, right = min(n, m), ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canAssign(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
