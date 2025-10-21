class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ) {
            int v = nums[i];
            int l = lower_bound(nums.begin(), nums.end(), v - k) - nums.begin();
            int r = upper_bound(nums.begin(), nums.end(), v + k) - nums.begin();
            int window = r - l;
            int occ = upper_bound(nums.begin(), nums.end(), v) - lower_bound(nums.begin(), nums.end(), v);
            res = max(res, min(window, occ + numOperations));
            i = upper_bound(nums.begin() + i, nums.end(), v) - nums.begin();
        }
        return res;
    }
};
