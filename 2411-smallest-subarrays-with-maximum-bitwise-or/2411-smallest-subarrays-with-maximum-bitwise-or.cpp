class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n), last(32, -1);
        for (int i = n - 1; i >= 0; --i) {
            for (int bit = 0; bit < 32; ++bit) {
                if ((nums[i] >> bit) & 1) {
                    last[bit] = i;
                }
            }
            int maxPos = i;
            for (int bit = 0; bit < 32; ++bit) {
                if (last[bit] != -1) {
                    maxPos = max(maxPos, last[bit]);
                }
            }
            answer[i] = maxPos - i + 1;
        }
        return answer;
    }
};
