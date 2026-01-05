class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negativeCount = 0;
        int minAbs = INT_MAX;

        for (auto& row : matrix) {
            for (int val : row) {
                sum += abs(val);
                if (val < 0) negativeCount++;
                minAbs = min(minAbs, abs(val));
            }
        }
if (negativeCount % 2 == 1) {
            sum -= 2LL * minAbs;
        }

        return sum;
    }
};
