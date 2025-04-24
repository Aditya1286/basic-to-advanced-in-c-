class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int total = unordered_set<int>(nums.begin(), nums.end()).size();
        int n = nums.size(), res = 0;
        unordered_map<int, int> freq;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            freq[nums[right]]++;
            while (freq.size() == total) {
                res += n - right;
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
        }
        return res;
    }
};
