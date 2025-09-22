class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxFreq = 0, ans = 0;
        for (int x : nums) {
            freq[x]++;
            maxFreq = max(maxFreq, freq[x]);
        }
        for (auto& [k,v] : freq) {
            if (v == maxFreq) ans += v;
        }
        return ans;
    }
};
