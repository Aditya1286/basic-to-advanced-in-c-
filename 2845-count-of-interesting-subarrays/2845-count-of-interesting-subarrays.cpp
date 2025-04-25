class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> freq;
        freq[0] = 1;
        long long result = 0;
        int prefixMod = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % modulo == k) {
                prefixMod = (prefixMod + 1) % modulo;
            } else {
                prefixMod = prefixMod % modulo;
            }

            int target = (prefixMod - k + modulo) % modulo;
            result += freq[target];
            freq[prefixMod]++;
        }

        return result;
    }
};
