class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxIdx = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIdx]) {
                maxIdx = i;
            }
        }

        vector<int> result;
        for (int i = maxIdx; i >= 0; i = prev[i]) {
            result.push_back(nums[i]);
            if (prev[i] == -1) break;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
