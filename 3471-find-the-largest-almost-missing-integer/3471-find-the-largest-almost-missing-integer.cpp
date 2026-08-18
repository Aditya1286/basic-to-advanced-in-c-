class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int i = 0; i <= n - k; i++) {

            unordered_set<int> seen;

            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }

            for (auto x : seen) {
                mp[x]++;
            }
        }

        int ans = INT_MIN;

        for (auto it : mp) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans == INT_MIN ? -1 : ans;
    }
};