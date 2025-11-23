#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxSumDivThree(std::vector<int>& nums) {
        const int NEG = INT_MIN / 2;
        int dp[3] = {0, NEG, NEG};
        for (int num : nums) {
            int tmp[3] = {dp[0], dp[1], dp[2]};
            int r = num % 3;
            for (int i = 0; i < 3; ++i) {
                int ni = (i + r) % 3;
                tmp[ni] = std::max(tmp[ni], dp[i] + num);
            }
            dp[0] = tmp[0]; dp[1] = tmp[1]; dp[2] = tmp[2];
        }
        return dp[0];
    }
};
