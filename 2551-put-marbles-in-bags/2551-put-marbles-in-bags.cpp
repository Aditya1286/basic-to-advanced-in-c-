class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;  

        vector<long long> pairwise_sums;
        for (int i = 0; i < n - 1; i++) {
            pairwise_sums.push_back(weights[i] + weights[i + 1]);
        }

        sort(pairwise_sums.begin(), pairwise_sums.end());

        long long minScore = 0, maxScore = 0;
        for (int i = 0; i < k - 1; i++) {
            minScore += pairwise_sums[i]; 
            maxScore += pairwise_sums[n - 2 - i];  
        }

        return maxScore - minScore;
    }
};
