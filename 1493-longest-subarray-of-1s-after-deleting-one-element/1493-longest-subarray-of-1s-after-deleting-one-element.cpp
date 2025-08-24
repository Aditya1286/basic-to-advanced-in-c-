class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, zeros = 0, ans = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] == 0) zeros++;

            while (zeros > 1) {
                if (nums[l] == 0) zeros--;
                l++;
            }

            ans = max(ans, r - l);
        }

        return ans;
    }
};
