#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for (int x : nums) if (x == 1) ones++;
        if (ones > 0) return n - ones;
        int g = nums[0];
        for (int x : nums) g = std::gcd(g, x);
        if (g != 1) return -1;
        int minLen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int cur = nums[i];
            if (cur == 1) { minLen = 1; break; }
            for (int j = i + 1; j < n; ++j) {
                cur = std::gcd(cur, nums[j]);
                if (cur == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return n + minLen - 2;
    }
};
