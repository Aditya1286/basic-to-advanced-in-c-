class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxNum = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int count = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] == maxNum) ++count;
            while (count == k) {
                if (nums[l++] == maxNum) --count;
            }
            ans += l;
        }
        return ans;
    }
};
