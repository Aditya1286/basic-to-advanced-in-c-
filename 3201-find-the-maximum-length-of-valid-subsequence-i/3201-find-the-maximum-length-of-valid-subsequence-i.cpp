class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size(), count_even = 0;
        for (int x : nums) if ((x & 1) == 0) ++count_even;
        int count_odd = n - count_even;
        int best_same = max(count_even, count_odd), best_alt = 0;
        for (int start = 0; start < 2; ++start) {
            int expected = start, len = 0;
            for (int x : nums) {
                if ((x & 1) == expected) {
                    ++len;
                    expected ^= 1;
                }
            }
            best_alt = max(best_alt, len);
        }
        return max(best_same, best_alt);
    }
};
