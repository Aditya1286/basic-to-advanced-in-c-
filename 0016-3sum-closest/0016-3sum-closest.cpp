class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];

                if (abs(currSum - target) < abs(closest - target)) {
                    closest = currSum;
                }

                if (currSum < target) {
                    ++left;
                } else if (currSum > target) {
                    --right;
                } else {
                    // Found exact match
                    return currSum;
                }
            }
        }

        return closest;
    }
};

