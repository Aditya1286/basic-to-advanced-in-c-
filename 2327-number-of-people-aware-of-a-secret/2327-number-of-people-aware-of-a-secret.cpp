class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1);
        dp[1] = 1;
        long long total = 0;
        
        for (int day = 2; day <= n; ++day) {
            for (int shareDay = max(1, day - forget + 1); shareDay <= day - delay; ++shareDay) {
                dp[day] = (dp[day] + dp[shareDay]) % MOD;
            }
        }
        
        for (int day = n - forget + 1; day <= n; ++day) {
            total = (total + dp[day]) % MOD;
        }
        
        return total;
    }
};
