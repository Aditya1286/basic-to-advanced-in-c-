class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            for (int x = 0; x < n; x++) {
                if ((x | (x + 1)) == n) {
                    ans[i] = x;
                    break;
                }
            }
        }
        return ans;
    }
};
