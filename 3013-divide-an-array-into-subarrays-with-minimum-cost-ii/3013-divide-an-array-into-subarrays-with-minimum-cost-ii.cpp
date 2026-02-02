class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int need = k - 1;
        int windowSize = dist + 1;

        multiset<int> small, large;
        long long sumSmall = 0;

        auto add = [&](int x) {
            if ((int)small.size() < need) {
                small.insert(x);
                sumSmall += x;
            } else if (!small.empty() && x < *prev(small.end())) {
                int v = *prev(small.end());
                small.erase(prev(small.end()));
                sumSmall -= v;
                large.insert(v);
                small.insert(x);
                sumSmall += x;
            } else {
                large.insert(x);
            }
        };

        auto remove = [&](int x) {
            auto it = small.find(x);
            if (it != small.end()) {
                sumSmall -= x;
                small.erase(it);
                if (!large.empty()) {
                    auto jt = large.begin();
                    int v = *jt;
                    large.erase(jt);
                    small.insert(v);
                    sumSmall += v;
                }
            } else {
                large.erase(large.find(x));
            }
        };

        for (int i = 1; i <= min(n - 1, windowSize); i++) add(nums[i]);

        long long ans = nums[0] + sumSmall;

        for (int i = windowSize + 1; i < n; i++) {
            add(nums[i]);
            remove(nums[i - windowSize]);
            ans = min(ans, nums[0] + sumSmall);
        }

        return ans;
    }
};
