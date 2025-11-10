#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ) {
            if (nums[i] == 0) {
                i++;
                continue;
            }
            
            int j = i;
            int mini = INT_MAX;

            while (j < n && nums[j] != 0) {
                mini = min(mini, nums[j]);
                j++;
            }

            for (int k = i; k < j; k++) {
                nums[k] = max(0, nums[k] - mini);
            }
            count++;
        }

        for (int x : nums) {
            if (x != 0) return count + minOperations(nums);
        }

        return count;
    }
};
