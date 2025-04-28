class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long res = 0;
        long long sum = 0;
        int r = 0;
        for (int l = 0; l < n; ++l) {
            while (r < n && (sum + nums[r]) * (r - l + 1) < k) {
                sum += nums[r++];
            }
            res += (r - l);
            sum -= nums[l];
        }
        return res;
    }
};
