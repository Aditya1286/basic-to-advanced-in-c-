class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG = -4e18;
        vector<vector<long long>> dp(k + 1, vector<long long>(3, NEG));
        dp[0][0] = 0;

        for (int p : prices) {
            vector<vector<long long>> ndp = dp;
            for (int t = 0; t <= k; t++) {
                if (dp[t][0] != NEG) {
                    ndp[t][1] = max(ndp[t][1], dp[t][0] - p);
                    ndp[t][2] = max(ndp[t][2], dp[t][0] + p);
                }
                if (dp[t][1] != NEG && t + 1 <= k) {
                    ndp[t + 1][0] = max(ndp[t + 1][0], dp[t][1] + p);
                }
                if (dp[t][2] != NEG && t + 1 <= k) {
                    ndp[t + 1][0] = max(ndp[t + 1][0], dp[t][2] - p);
                }
            }
            dp.swap(ndp);
        }

        long long ans = 0;
        for (int t = 0; t <= k; t++) ans = max(ans, dp[t][0]);
        return ans;
    }
};
