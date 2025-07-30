class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int m = 0;
        for (int x : nums) {
            if (x > m) m = x;
        }

        int best = 0, cur = 0;
        for (int x : nums) {
            if (x == m) {
                cur++;
                if (cur > best) best = cur;
            } else {
                cur = 0;
            }
        }

        return best;
    }
};
