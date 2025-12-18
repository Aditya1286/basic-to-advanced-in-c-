class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long base = 0;
        for (int i = 0; i < n; ++i) base += 1LL * strategy[i] * prices[i];
        int half = k / 2;
        vector<long long> left(n), right(n);
        for (int i = 0; i < n; ++i) {
            left[i] = -1LL * strategy[i] * prices[i];
            right[i] = 1LL * prices[i] - 1LL * strategy[i] * prices[i];
        }
        vector<long long> prefL(n + 1, 0), prefR(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefL[i + 1] = prefL[i] + left[i];
            prefR[i + 1] = prefR[i] + right[i];
        }
        long long best = 0;
        for (int l = 0; l + k <= n; ++l) {
            long long sum = (prefL[l + half] - prefL[l]) + (prefR[l + k] - prefR[l + half]);
            if (sum > best) best = sum;
        }
        return base + best;
    }
};
