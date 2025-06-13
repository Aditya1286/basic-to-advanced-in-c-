class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();

        auto canFormPairs = [&](int maxDiff) {
            int pairs = 0;
            for (int i = 1; i < nums.size(); ) {
                if (nums[i] - nums[i - 1] <= maxDiff) {
                    pairs++;
                    i += 2;
                } else {
                    i++;
                }
            }
            return pairs >= p;
        };

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canFormPairs(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
