class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxLength = 0;

        for (int num : nums) {
            freq[num]++;
        }

        for (auto& [key, val] : freq) {
            if (freq.count(key + 1)) {
                maxLength = max(maxLength, val + freq[key + 1]);
            }
        }

        return maxLength;
    }
};
