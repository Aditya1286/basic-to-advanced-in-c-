class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        const long long INF = (long long)9e18;
        // min prefix sum for each remainder modulo k
        vector<long long> minPref(k, INF);
        // prefix sum
        long long pref = 0;
        // prefix at index 0 = 0 has remainder 0
        minPref[0] = 0;
        long long ans = LLONG_MIN;

        for (int j = 1; j <= n; ++j) {
            pref += nums[j-1];            // pref = sum nums[0..j-1]
            int r = j % k;
            // if we have a previous prefix with same remainder, candidate is valid
            if (minPref[r] != INF) {
                ans = max(ans, pref - minPref[r]);
            }
            // update the minimum prefix for this remainder
            minPref[r] = min(minPref[r], pref);
        }

        return ans;
    }
};
